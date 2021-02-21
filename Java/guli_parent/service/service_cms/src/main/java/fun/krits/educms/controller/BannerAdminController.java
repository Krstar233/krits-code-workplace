package fun.krits.educms.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import fun.krits.commonutils.Result;
import fun.krits.educms.entity.CrmBanner;
import fun.krits.educms.service.CrmBannerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@CrossOrigin
@RequestMapping("/educms/banneradmin")
public class BannerAdminController {

    @Autowired
    private CrmBannerService bannerService;

    //分页查询banner
    @GetMapping("pageBanner/{page}/{limit}")
    public Result pageBanner(@PathVariable long page, @PathVariable long limit){
        Page<CrmBanner> bannerPage = new Page<>(page, limit);
        bannerService.page(bannerPage, null);
        return Result.ok().data("items", bannerPage.getRecords()).data("total", bannerPage.getTotal());
    }

    //添加 banner
    @PostMapping("addBanner")
    public Result addBanner(@RequestBody CrmBanner crmBanner){
        bannerService.save(crmBanner);
        return Result.ok().message("添加成功！");
    }

    //修改Banner
    @PutMapping("update")
    public Result updateById(@RequestBody CrmBanner banner){
        bannerService.updateById(banner);
        return Result.ok().message("更新成功！");
    }

    // 删除Banner
    @DeleteMapping("remove/{id}")
    public Result remove(@PathVariable String id){
        bannerService.removeById(id);
        return Result.ok().message("删除成功！");
    }

    // 获取Banner
    @GetMapping("get/{id}")
    public Result getById(@PathVariable String id){
        CrmBanner banner = bannerService.getById(id);
        return Result.ok().data("banner", banner);
    }
}
