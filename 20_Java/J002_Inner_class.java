class Emp {

    // normal inner class.
    class Inner {

        Inner() {
            System.out.println("inside inner");
        }

    }

    // static inner class.
    static class Inner1 {
        Inner1() {
            System.out.println("inside static inner");
        }
    }
};

public class J002_Inner_class {

    public static void main(String[] args) {

        Emp obj = new Emp();

        // To create object of inner class , object of upper class is used.
        Emp.Inner obj1 = obj.new Inner();

        // for a static class , no need of object of upper class.
        Emp.Inner1 obj2 = new Emp.Inner1();
    }
}
