interface ClassAMethodType {
    void methodOfClassA();
}

class Root {

}

public class ClassB {

    ClassAMethodType cb;


    public ClassB checkClassAHasMethod(ClassA parent) {
        try {
            cb = (ClassAMethodType) parent;
        }
        catch (ClassCastException e) {
           throw new RuntimeException("ClassA does not have method `methodOfClassA`");
        }
        return this;
    }


    public void callMethodOfClassA() {
        if(cb != null) {
            System.out.println("Calling methodOfClassA from ClassB");
            cb.methodOfClassA();
        }
    }
}
