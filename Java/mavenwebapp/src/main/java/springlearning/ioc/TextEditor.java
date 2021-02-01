package springlearning.ioc;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component("textEditor")
public class TextEditor {
    private SpellChecker spellChecker;
    public TextEditor(){}
    @Autowired
    public TextEditor(SpellChecker spellChecker){
        System.out.println("Inside TextEditor constructor." );
        this.spellChecker = spellChecker;
    }
    
    public void init(){
        System.out.println("textEditor : init");
    }

    public void destroy(){
        System.out.println("textEditor : destroy");
    }
    public void spellCheck(){
        spellChecker.checkSpelling();
    }

    public void setSpellChecker(SpellChecker spellChecker) {
        this.spellChecker = spellChecker;
    }

    public SpellChecker getSpellChecker() {
        return spellChecker;
    }
}
