package fun.krits.eduservice.service;

import fun.krits.eduservice.entity.EduCourse;
import com.baomidou.mybatisplus.extension.service.IService;
import fun.krits.eduservice.entity.vo.CourseInfoVo;
import fun.krits.servicebase.exception.MyException;

/**
 * <p>
 * 课程 服务类
 * </p>
 *
 * @author krits
 * @since 2021-02-01
 */
public interface EduCourseService extends IService<EduCourse> {
    void saveCourseInfo(CourseInfoVo vo);
}
