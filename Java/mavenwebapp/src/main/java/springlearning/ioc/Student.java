package springlearning.ioc;

import org.springframework.beans.factory.annotation.Required;

public class Student {
    private Integer age;
    private String name;
    @Required
    public void setName(String name) {
        this.name = name;
    }
    @Required
    public void setAge(Integer age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public Integer getAge() {
        return age;
    }
}
