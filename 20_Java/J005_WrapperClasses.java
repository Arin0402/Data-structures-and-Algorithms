
public class J005_WrapperClasses {

    public static void main(String[] args) {

        int i = 5; // primitive data type.

        Integer ii = new Integer(5); // wraper class - Integer. ii is the object.
        int j = ii.intValue(); // accessing value.

        // other method of declaring and accessing value.
        // Integer ii = 5;
        // int j = ii.

        // Example;
        String s = "123";
        int k = Integer.parseInt(s); // parseInt is a static method so it is called using class Integer.

    }
}
