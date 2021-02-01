import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Random;

public class BannerDAO {
    private static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    private static final String DATABASE = "jdbc:mysql://localhost/test";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";
    private Connection conn;

    public BannerDAO(){
        try {
            // 注册驱动程序
            Class.forName(JDBC_DRIVER);
            // 连接数据库
            conn = DriverManager.getConnection(DATABASE+"?user="+USERNAME+"&password="+PASSWORD);
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
    // 查询 Banner
    public Banner selectById(Integer id) throws SQLException, IOException {
        String sql = "select * from banner where id="+id;
        Statement statement = conn.createStatement();
        ResultSet rs = statement.executeQuery(sql);
        if (rs.next()){
            String link = rs.getString("link");
            String type = rs.getString("type");
            InputStream in = rs.getBinaryStream("file");
            byte[] file = in.readAllBytes();
            Banner banner = new Banner();
            banner.setId(id);
            banner.setLink(link);
            banner.setType(type);
            banner.setFile(file);
            rs.close();
            statement.close();
            return banner;
        }
        rs.close();
        statement.close();
        return null;
    }
    // 通过id查询Banner的Link
    public String selectLinkById(Integer id) throws SQLException {
        String sql = "select link from banner where id=" + id;
        Statement st = conn.createStatement();
        ResultSet rs = st.executeQuery(sql);
        if (rs.next()){
            String link = rs.getString(1);
            st.close();
            rs.close();
            return link;
        }
        rs.close();
        st.close();
        return null;
    }
    // 插入 Banner
    public void insert(Banner banner) throws SQLException {
        String sql = "insert into banner(link, type, file) values (?,?,?)";
        PreparedStatement pst = conn.prepareStatement(sql);
        pst.setString(1,banner.getLink());
        pst.setString(2,banner.getType());
        pst.setBinaryStream(3,new ByteArrayInputStream(banner.getFile()));
        pst.execute();
        pst.close();
    }
    // 获取随机Banner的id
    public Integer getRandomBannerId() throws SQLException {
        String sql = "select id from banner";
        Statement st = conn.createStatement();
        if (st == null)
            return null;
        ResultSet rs = st.executeQuery(sql);
        rs.last();
        int rows = rs.getRow();
        if (rows == 0)
            return null;
        Random r = new Random();
        int row = Math.abs(r.nextInt()) % rows;
        rs.absolute(1);
        while(row-- != 0 && rs.next());
        int id = rs.getInt(1);
        rs.close();
        st.close();
        return id;
    }
}
