package org.example.mapper;

import org.example.pojo.Student;

public interface StudentMapper {
    Student selectStudentById(Integer id);
    int insert(Student student);
    int updateByPrimaryKey(Student student);
    int deletByPrimaryKey(Integer id);
}