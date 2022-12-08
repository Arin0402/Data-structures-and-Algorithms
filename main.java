
class Emp {

    int a;
    int b;
    static int c;

    Emp(int a, int b) {
        this.a = a;
        this.b = b;
    }

    static class Inner {

        Inner() {
            System.out.println("inside inner");
        }
    }
};

class main {

    public static void main(String args[]) {

        Emp obj = new Emp(1, 2);
        Emp.Inner obj1 = new Emp.Inner();
    }
}