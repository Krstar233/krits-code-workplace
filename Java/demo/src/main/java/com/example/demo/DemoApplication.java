package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Map;

@SpringBootApplication
@RestController
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}

	@GetMapping("/hello")
	public String SayHello(@RequestParam(value = "name", defaultValue = "world") String name){
		return String.format("<h1>Hello %s!</h1>",name);
	}

	@PostMapping("/text")
	public Map<String, String> PrintText(@RequestParam(value = "text", defaultValue = "No Message!") String text){
		System.out.println(text);
		Map<String, String> ret = new HashMap<>();
		ret.put("code", "200");
		return ret;
	}
}