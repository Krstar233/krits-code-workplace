package mvc;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping("/helloworld")
public class HelloController {
    @RequestMapping(method = RequestMethod.GET)
    public String hello(Model model){
        model.addAttribute("msg","YOOFUR+");
        return "hello";
    }
}
