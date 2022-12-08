
// video link - https://youtu.be/8cm1x4bC610?t=13894.
class A {

    public void show() {
        System.out.println("in A");
    }

};

public class J009_AnonymousClass {

    public static void main(String[] args) {

        A a = new A() { // this defines new class whose scope is limited to this object;

            public void show() {
                System.out.println("in anonymous class");
            }

            public void show1() { // Here show method can not be called as the object is of refrence of class A ,
                                  // and in class A we do not have method show1 declared.
                System.out.println("in anonymous class show1 method");
            }

            // so annonymous class is used to override the methods of refrence class (Here
            // A).
        };

        a.show();
        // a.show1(); //error
    }
}
