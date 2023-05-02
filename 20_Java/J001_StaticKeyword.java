
class Emp {

    int id;
    int salary;
    static String ceo;

    // inititalise static variables. It is called when you load a class .
    // This is called only once no matter how may the objects are.
    // Called before the constructor.
    static {
        ceo = "niki";
    }

    Emp() {
        id = 1;
        salary = 3000;
    }

    public void show() {
        System.out.println("id " + id);
        System.out.println("slalry " + salary);
        System.out.println("ceo " + ceo);

    }
};

public class J001_StaticKeyword {

    public static void main(String[] args) {

        Emp e1 = new Emp();

        // can also change the value of static variable using class name.
        // Emp.ceo = "mahesh";

        e1.show();
    }
}
