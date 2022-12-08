abstract class writer {

    public abstract void show();
};

class Pen extends writer {

    public void show() {
        System.out.println("pen");
    }
};

class Pencil extends writer {

    public void show() {
        System.out.println("pencil");
    }
};

class A {

    public void display(writer w) { // accepting object of abstract class.

        w.show(); // calling the function of that particular object. (pen or pencil)
    }
}

class J007_AbstractClass_Example {

    public static void main(String args[]) {

        A a = new A();

        Pen pen = new Pen();
        Pencil pencil = new Pencil();

        // a.display(pen);
        a.display(pencil);

    }
}
