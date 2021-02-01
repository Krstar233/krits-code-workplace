package springlearning.ioc;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void test1(){
        AbstractApplicationContext context = new ClassPathXmlApplicationContext("Beans.xml");
        HelloWorld obj = (HelloWorld) context.getBean("helloworld");
        obj.getMessage1();
        obj.setMessage1("I'm Object A");
        HelloWorld obj2 = (HelloWorld) context.getBean("helloworld");
        obj2.getMessage1();
        if (obj == obj2){
            System.out.println("Same Object!");
        }
        obj.getMessage1();
        obj.getMessage2();
        Minecraft mc = (Minecraft) context.getBean("minecraft");
        mc.getMessage1();
        mc.getMessage2();
        mc.getMessage3();
        context.registerShutdownHook();
    }
    public static void test2(){
        AbstractApplicationContext context = new ClassPathXmlApplicationContext("Beans2.xml");
        TextEditor te = (TextEditor) context.getBean("textEditor");
        te.spellCheck();

        JavaCollection jc = (JavaCollection) context.getBean("javaCollection");
        jc.getAddressList();
        jc.getAddressMap();
        jc.getAddressSet();
        jc.getAddressProp();

        Student student = (Student) context.getBean("student");
        System.out.println("Name: " + student.getName());
        System.out.println("Age: " + student.getAge());

        context.registerShutdownHook();
    }
    public static void main(String[] args) {
        test2();
    }
}
