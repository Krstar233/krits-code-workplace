package springlearning.aop;

import org.aspectj.lang.annotation.*;

@Aspect
public class Logging {
    @Pointcut("execution(* springlearning.aop.Student.*(..))")
    public void selectAll(){}

    @Before("selectAll()")
    public void beforeAdvice(){
        System.out.println("Going to setup student profile.");
    }
    @After("selectAll()")
    public void afterAdvice(){
        System.out.println("Student profile has been setup.");
    }
    @AfterReturning(pointcut = "selectAll()", returning = "retVal")
    public void afterReturnAdvice(Object retVal){
        System.out.println("Returning:" + retVal.toString() );
    }
    @AfterThrowing(pointcut = "selectAll()", throwing = "ex")
    public void afterThrowingAdvice(IllegalAccessException ex){
        System.out.println("There has been an exception: " + ex.toString());
    }
}
