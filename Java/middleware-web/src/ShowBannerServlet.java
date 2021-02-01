import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

public class ShowBannerServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        BannerDAO bannerDAO = new BannerDAO();
        resp.setContentType("text/html;charset=UTF-8");
        try {
            // 从数据库中获取随机id
            Integer id = bannerDAO.getRandomBannerId();
            if (id == null)
                return;
            // 根据id获取链接
            String link = bannerDAO.selectLinkById(id);
            PrintWriter pw = resp.getWriter();
            // 输出图片到Web页面
            pw.println("<a href=\""+ link + "\"><img border=0 src=\"showImage?id="+id+"\"></a>");
            pw.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
}
