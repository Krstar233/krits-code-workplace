package springlearning.ioc;

import org.springframework.stereotype.Component;

@Component("spellChecker")
public class SpellChecker {
    public SpellChecker(){
        System.out.println("Inside SpellChecker constructor." );
    }
    public void checkSpelling() {
        System.out.println("Inside checkSpelling." );
    }
}
