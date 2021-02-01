package fun.krits.eduservice.service.impl;

import fun.krits.eduservice.entity.EduCourse;
import fun.krits.eduservice.entity.EduCourseDescription;
import fun.krits.eduservice.entity.vo.CourseInfoVo;
import fun.krits.eduservice.mapper.EduCourseMapper;
import fun.krits.eduservice.service.EduCourseDescriptionService;
import fun.krits.eduservice.service.EduCourseService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import fun.krits.servicebase.exception.MyException;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;

/**
 * <p>
 * 课程 服务实现类
 * </p>
 *
 * @author krits
 * @since 2021-02-01
 */
@Service
public class EduCourseServiceImpl extends ServiceImpl<EduCourseMapper, EduCourse> implements EduCourseService {
    @Autowired
    private EduCourseDescriptionService courseDescriptionService;

    //添加课程基本信息
    @SneakyThrows
    @Override
    public void saveCourseInfo(CourseInfoVo vo){
        //1. 课程表中添加课程基本信息
        EduCourse course = new EduCourse();
        BeanUtils.copyProperties(vo, course);
        course.setGmtCreate(new Date()); course.setGmtModified(new Date());
        int insert = baseMapper.insert(course);
        if (insert <= 0){
            //添加失败
            throw new MyException("添加课程信息失败");
        }

        //2. 向课程表添加课程简介
        EduCourseDescription description = new EduCourseDescription();
        description.setDescription(vo.getDescription());
        description.setGmtCreate(new Date()); description.setGmtModified(new Date());
        courseDescriptionService.save(description);
    }
}
