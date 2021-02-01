package springlearning.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
public class RestfulController {
    @GetMapping("/greeting")
    public String hello(){
        Map<String, String> m = new HashMap<>();
        m.put("text", "name");
        return m.toString();
    }
}
