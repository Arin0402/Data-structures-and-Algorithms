// https://youtu.be/8cm1x4bC610?t=14092

interface Abc { // This is functional interface as it has only one "abstract" method.

    void show();

}

public class J010_AnonymousClass_with_Interface {

    public static void main(String[] args) {

        Abc obj = new Abc() { // we can create object of interface using anonymous class.
            public void show() {
                System.out.println("in anonymous class show");
            }

        };

        // we can also write this as
        // Abc obj = () -> System.out.println("in anonymous class show"); // This is
        // lambda expression. Only works with functional interfaces.

        obj.show();
    }
}
