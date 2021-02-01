import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

public class ShowImage extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        BannerDAO bannerDAO = new BannerDAO();
        try {
            // 获取参数id
            Integer id = Integer.parseInt(req.getParameter("id"));
            // 根据id从数据库中获取Banner对象
            Banner banner = bannerDAO.selectById(id);
            resp.setContentType(banner.getType());
            ServletOutputStream out = resp.getOutputStream();
            // 以流的形式输出图片数据
            out.write(banner.getFile());
            out.flush();
            out.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
