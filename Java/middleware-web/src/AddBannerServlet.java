import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.sql.SQLException;

@MultipartConfig
public class AddBannerServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html;charset=UTF-8");
        // 显示表单界面
        PrintWriter out = resp.getWriter();
        String html = "<html>\n" +
                "  <head>\n" +
                "    <title>addBanner</title>\n" +
                "  </head>\n" +
                "    <h3>上传图片</h3>\n" +
                "  <form action=\"addBanner\" method=\"post\" enctype=\"multipart/form-data\">\n" +
                "    链接：<input type=\"text\" size=20 name=\"link\"><br>\n" +
                "    图片：<input type=\"file\" size=20 name=\"file\"><br>\n" +
                "    <input type=\"submit\" value=\"确认提交\">\n" +
                "  </form>\n" +
                "  </body>\n" +
                "</html>";
        out.print(html);
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=UTF-8");
        PrintWriter out = resp.getWriter();
        // 读取表单数据
        String link = req.getParameter("link"); // 链接
        Part part = req.getPart("file");
        // 读取文件数据
        String contentType = part.getContentType(); // 文件类型
        InputStream in = part.getInputStream();
        byte[] fileData = in.readAllBytes();    // 文件数据
        // 表单验证
        if (link.equals("") || fileData.length == 0){
            out.println("数据不完整，请重新输入");
            doGet(req, resp);
            return;
        }
        // 存储表单数据到Banner对象
        Banner banner = new Banner();
        banner.setType(contentType);
        banner.setLink(link);
        banner.setFile(fileData);
        // 存储对象 Banner
        try {
            BannerDAO bannerDAO = new BannerDAO();
            bannerDAO.insert(banner);
            out.println("链接和图片已经存储到数据库");
        } catch (SQLException throwables) {
            out.println("链接和图片存储失败！");
            throwables.printStackTrace();
        }
        doGet(req, resp);
    }
}
