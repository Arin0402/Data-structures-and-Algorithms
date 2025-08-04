
class A {

    public void show() {
        System.out.println("in A");
    }

};

class B extends Practice {

    // To give compile time error if this method is not overloading the method of
    // the super class.
    // if we change the spelling to show1 , then it will throw error as method is
    // not overloading the method of the super class.
    // if we do not use override and change the spelling to show1 , then method of
    // super class will be called.
    @Override
    public void show1() {
        System.out.println("in B");
    }

};

public class J004_Overridingdemo {

    public static void main(String[] args) {

        B b = new B();
        b.show();
    }
}
