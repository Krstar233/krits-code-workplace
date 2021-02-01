package fun.krits.eduservice.controller;


import fun.krits.commonutils.Result;
import fun.krits.eduservice.entity.vo.CourseInfoVo;
import fun.krits.eduservice.service.EduCourseService;
import fun.krits.servicebase.exception.MyException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 课程 前端控制器
 * </p>
 *
 * @author krits
 * @since 2021-02-01
 */
@RestController
@CrossOrigin
@RequestMapping("/eduservice/edu-course")
public class EduCourseController {
    @Autowired
    private EduCourseService courseService;

    @PostMapping("addCourseInfo")
    public Result addCourseInfo(@RequestBody CourseInfoVo vo){
        courseService.saveCourseInfo(vo);
        return Result.ok();
    }
}

