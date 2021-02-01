package connectionpool;

import java.sql.*;
public class JDBCTest {
    public static final String URL = "jdbc:mysql://localhost:3306/mydb?serverTimezone=UTC";
    public static final String USER = "root";
    public static final String PASSWORD = "";

    public static void main(String[] args) throws Exception {

        long startTime = System.nanoTime();
        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");

        int t = 1000;
        while (t-- != 0){
            //获取连接
            Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
            Connection connection2 = DriverManager.getConnection(URL, USER, PASSWORD);
            //Statement接口
            Statement statement = connection.createStatement();
            String sql1 = "insert into person (name, age) values ('kr', 25)";
            statement.executeUpdate(sql1);

            //PreparedStatement接口
            String sql2 = "insert into person (name, age) values ('kr', 15)";
            PreparedStatement preparedStatement = connection.prepareStatement(sql2);
            preparedStatement.execute();

            //关闭连接
            connection.close();
            connection2.close();
        }

        long endTime = System.nanoTime();

        System.out.println((endTime-startTime)/1000000000.0);
    }
}
