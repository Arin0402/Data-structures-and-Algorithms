
abstract class A { // We can not create object of abstract class because there is definition of
                   // methods in it.

    public abstract void eat(); // abstract method.

    void drink() { // we can define methods in abstract class.
        System.out.println("drinking");
    }

}

class B extends A { // concrete class

    public void eat() { // the abstract method needs to declared in concrete class.

        System.out.println("eating...");
    }
}

public class J006_AbstractClass {

    public static void main(String[] args) {

        B b = new B();
        b.eat();
        b.drink();

    }
}

// Why do we need abstract class
// https://youtu.be/8cm1x4bC610?t=12520