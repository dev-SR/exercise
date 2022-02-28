import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class RunTime{
    void onRunTime(){
        ClassA a = new ClassA();
        ClassB b = new ClassB().checkClassAHasMethod(a);
        b.callMethodOfClassA();
    }
}
public class InterfaceUseCase {
    @Test
    @DisplayName("Verify that the method call is working")
    void test1() {
      new RunTime().onRunTime();
    }
}
