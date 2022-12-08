
class parent {

    parent() {
        System.out.println("PARENT");
    }

    parent(String name) {
        System.out.println(name);
    }

}

class child extends parent {

    child(String name) {

        super(name); // It is calling the parameterised constructor of the parent
        // class . If not used , then the normal constructor of the parent class will be
        // called.
        System.out.println("CHILD");
    }

}

public class J015_Constructor_IMP {

    public static void main(String[] args) {

        child ob = new child("name");

    }
}
