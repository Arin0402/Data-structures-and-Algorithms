class MyObject {

    int val;

    static void changeReference(MyObject o) {
        o.val = 20; // This changes the reference to a new object
        System.out.println(o.val); // Output: 10
    }

    MyObject(int val) {
        this.val = val;
    }

    public static void main(String[] args) {
        MyObject obj = new MyObject(10);
        changeReference(obj);
        System.out.println(obj.val); // Output: 10
    }
}
