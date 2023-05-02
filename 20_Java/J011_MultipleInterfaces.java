import java.io.ObjectInputFilter.Status;

interface Demo {

    default static void show() {
        System.out.println("in Demo");
    }
}

interface Demo1 {
    default void show() {
        System.out.println("in Demo1");
    }
}

class DemoImp implements Demo, Demo1 {

    @Override
    public void show() { // Declare method to solve the ambiguity;

        // System.out.println("in show"); // either declare body;
        // Demo.super.show(); // or call the super interface method.
        Demo1.super.show();
    }

};

public class J011_MultipleInterfaces {

    public static void main(String[] args) {

        Demo obj = new DemoImp();

        obj.show();

    }
}
