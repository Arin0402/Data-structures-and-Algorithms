import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.Stack;
import java.util.Vector;
import java.util.function.BiPredicate;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

interface Human {

    abstract void func1();

    abstract void func2();

    default int getAge() {
        return 23;
    }

    // default void setAge(int age){
    // this.age = age;
    // }

}

class myCustomException extends Exception {
    public myCustomException(String Message) {
        super(Message);
    }
}

class myCustomExceptionChild extends myCustomException {
    myCustomExceptionChild(String Message) {
        super(Message);
    }
}

class Person implements Human {

    private int id;
    private String name;

    Person(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void func1() {
        System.out.println("fun1");
    }

    public void func2() {
        System.out.println("fun2");
    }

    public void func3(){
        System.out.println("fun3");
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;

        Person p = (Person) o;

        return id == p.id && name == p.name;
    }
}

class MyGenericClass<T> {

    T age;

    MyGenericClass(T age) {
        this.age = age;
    }

    T getAge() {
        return age;
    }

}

@FunctionalInterface
interface Calculator {
    int operation(int a, int b);

    default void helper() {
        System.out.println("Hi");
    }
}

@FunctionalInterface
interface MyFunctionalInterface<T, E> {
    T apply(T a, E b);
}


abstract class Shape {

    protected int length;
    abstract void calculateArea();

}

class Rectangle extends Shape {

    Rectangle(){
        this.length = 10;    
    }

    void calculateArea(){        
        System.out.println("From reactangle" + this.length);
    }           
}

class Circle extends Shape {

    Circle(){
        this.length = 20;    
    }

    void calculateArea(){        
        System.out.println("From circle" + this.length);
    }           
}



public class Practice {

    public static void main(String[] args) {

        // Person p1 = new Person(1, "a");
        // Person p2 = new Person(1, "a");

        // MyGenericClass<Integer> myGenericClass = new MyGenericClass<Integer>(23);
        // System.out.println(myGenericClass.getAge());
        
        // System.out.println(p1.getAge());
        // try {
        //     throw new myCustomException("sdf");
        // } catch (myCustomExceptionChild e) {
        //     System.out.println(e.getMessage());
        // } catch (myCustomException e) {
        //     System.out.println(e.getMessage());
        // }

        // List<Integer> list = new ArrayList<>();
        // list.add(1);
        // list.add(2);

        // Iterator<Integer> itr = list.iterator();

        // while (itr.hasNext()) {
        //     System.out.println(itr.next());
        // }

        // HashMap<Integer, String> mp = new HashMap<>();

        // mp.put(1, "A");
        // mp.put(2, "B");

        // Set<java.util.Map.Entry<Integer, String>> keys = mp.entrySet();

        // for (java.util.Map.Entry<Integer, String> entry : keys) {
        //     System.out.println(entry.getKey() + " " + entry.getValue());
        // }

        // ****** The functional interfaces

        // Calculator addition = (x, y) -> x + y;
        // System.out.println(addition.operation(1, 2));
        // addition.helper();

        // MyFunctionalInterface<Long, Long> add = (x, y) -> x + y;
        // System.out.println(add.apply(3L, 4L));

        // Function<Long, Long> func = (x) -> x + 10;
        // System.out.println(func.apply(3L));

        // Predicate<Integer> predicate = (x) -> x > 10;
        // System.out.println(predicate.test(3));

        // BiPredicate<Integer, Integer> biPredicate = (x, y) -> x > y;
        // System.out.println(biPredicate.test(4, 6));

        // Supplier<Integer> supplier = () -> 34;
        // System.out.println(supplier.get());

        // Consumer<Integer> cons = (x) -> System.out.println(x);
        // cons.accept(34);

        // *************

        Human human1 = new Person(2, "Arin");

        Shape shape = new Rectangle();
        shape.calculateArea();
        
    }
}







