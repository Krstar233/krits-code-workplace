package com.example;

import com.example.entity.User;
import com.example.mapper.UserMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;
import java.util.List;

@SpringBootTest
public class UserServiceTest {

    @Autowired
    private UserMapper userMapper;

    @Test
    public void findAll(){
        List<User> users = userMapper.selectList(null);
        System.out.println(users);
    }

    @Test
    public void addUser(){
        User user = new User();
        user.setName("Kri");
        user.setAddress("xxsdsqd");
        user.setSex("男");
        user.setCreateTime(new Date());
        user.setUpdateTime(new Date());

        userMapper.insert(user);
    }

    @Test
    public void TestOptimisticLock(){
        User user = userMapper.selectById("1345725398751752194");
        user.setSex("女");
        userMapper.updateById(user);
    }

    @Test
    public void updateTest(){
        User user = new User();
        user.setName("王明");
        user.setId("68");
        userMapper.updateById(user);
    }
}

