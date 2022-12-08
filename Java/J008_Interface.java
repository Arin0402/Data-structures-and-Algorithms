
interface writer { // object can not be created

    void show(); // by default all the methods are public abstract in interface

    default public void show1() { // we can define normal methods in interfacae using default keyword
        System.out.println("in show1");
    }

    static void diaplay() {
        System.out.println("display");
    }
}

class pen implements writer { // we use implements for interfaces

    public void show() {
        System.out.println("pen");
    };
};

class pencil implements writer {

    public void show() {
        System.out.println("pencil");
    };
};

class Kit {

    public void doSomething(writer w) {

        w.show();
    }
}

public class J008_Interface {

    public static void main(String[] args) {

        Kit k = new Kit();

        pen p = new pen();
        // or writer p = new pen();

        k.doSomething(p);

        // static method
        writer.diaplay();

    }

}

// Difference b/w abstract class and interface

// - a class can not extendes two abstract classes as multiple inheritance is
// not supported.
// - a class can implement multiple interfaces.
// -
