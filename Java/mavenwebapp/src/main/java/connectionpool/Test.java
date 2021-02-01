package connectionpool;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.util.Properties;

public class Test {

    public static void main(String[] args) throws Exception {

        long startTime = System.nanoTime();
        //数据源配置
        Properties properties=new Properties();
        //通过当前类的class对象获取资源文件
        InputStream is = Test.class.getResourceAsStream("/druid.properties");
        properties.load(is);
        //返回的是DataSource，不是DruidDataSource
        DataSource dataSource = DruidDataSourceFactory.createDataSource(properties);
        int t = 1000;
        while (t-- != 0){
            //获取连接
            Connection connection = dataSource.getConnection();
            Connection connection2 = dataSource.getConnection();
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