package fun.krits.yunpan.controller;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;
import java.io.*;

@RestController
public class YunpanController {

    @PostMapping("yunpan")
    public String upload(@RequestParam("files") MultipartFile[] files){
        String path = "./fileupload/";
        
        for (MultipartFile file : files){
            try(FileOutputStream fileOutputStream = new FileOutputStream(path + file.getOriginalFilename())){
                fileOutputStream.write(file.getBytes());
            } catch (Exception e) {
                e.printStackTrace();
                return "上传失败!";
            }
        }
        return "上传成功!";
    }
}
