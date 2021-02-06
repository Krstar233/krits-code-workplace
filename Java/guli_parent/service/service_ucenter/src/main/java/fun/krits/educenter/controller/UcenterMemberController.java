package fun.krits.educenter.controller;


import fun.krits.commonutils.Result;
import fun.krits.educenter.entity.vo.LoginVo;
import fun.krits.educenter.entity.vo.RegisterVo;
import fun.krits.educenter.service.UcenterMemberService;
import fun.krits.educenter.utils.TokenUtil;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.Map;

/**
 * <p>
 * 会员表 前端控制器
 * </p>
 *
 * @author krits
 * @since 2021-02-21
 */
@RestController
@CrossOrigin
@RequestMapping("/educenter/member")
public class UcenterMemberController {
    @Autowired
    private UcenterMemberService memberService;

    //登录
    @ApiOperation(value = "会员登陆")
    @PostMapping("login")
    public Result loginUer(@RequestBody LoginVo member){
        String token = memberService.login(member);
        return Result.ok().data("token", token);
    }

    //注册
    @ApiOperation(value = "会员注册")
    @GetMapping("register")
    public Result register(@RequestBody RegisterVo member){
        memberService.register(member);
        return Result.ok().message("注册成功！");
    }

    @ApiOperation(value = "根据token获取登录信息")
    @GetMapping("getLoginInfo")
    public Result getLoginInfo(HttpServletRequest request){
        Map<String, Object> tokenBody = TokenUtil.getTokenBody(request);
        String MemberId = (String) tokenBody.get("id");
        LoginVo loginVo = memberService.getLoginVo(MemberId);
        return Result.ok().data("item", loginVo);
    }
}