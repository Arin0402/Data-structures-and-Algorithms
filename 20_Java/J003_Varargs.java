
class Emp {

    public void add(int... n) { // this n here behaves as array.

        int sum = 0;

        for (int i : n)
            sum += i;

        System.out.println(sum);
    }
};

class J003_Varargs {

    public static void main(String args[]) {

        Emp obj = new Emp();

        obj.add(1, 2, 3, 4, 3, 5, 4); // can pass any number of arguments.
    }
}