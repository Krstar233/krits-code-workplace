package org.example;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.example.mapper.StudentMapper;
import org.example.pojo.Student;

import java.io.IOException;
import java.io.InputStream;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) throws IOException {
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        try (SqlSession session = sqlSessionFactory.openSession()){
            // select
            StudentMapper mapper = session.getMapper(StudentMapper.class);
            Student student = mapper.selectStudentById(1);
            System.out.println(student);

            // insert
            Student stu = new Student();
            stu.setId(10);
            stu.setAge(18);
            stu.setName("Jack");
            System.out.println("insert:" + mapper.insert(stu));

            // update
            Student stu2 = new Student();
            stu2.setId(10);
            stu2.setName("Jack Mar");
            stu2.setAge(49);
            System.out.println("update:" + mapper.updateByPrimaryKey(student));

            // delete
            System.out.println("delete:" + mapper.deletByPrimaryKey(10));

            // *********** 提交事务 **********
            session.commit();
        }
    }
}
