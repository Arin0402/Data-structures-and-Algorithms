You are using a class from a library
(say Student). You have a list of
Student objects. You need to sort this
list based on first name. How will
you do it? Constraint: (You do not
have the ability to change the source
code of the Student class)

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class StudentSorter {
public static void main(String[] args) {
List<Student> studentList = /_ Initialize your list of Student objects _/;

        // Create a custom comparator based on first names
        Comparator<Student> firstNameComparator = new Comparator<Student>() {
            @Override
            public int compare(Student student1, Student student2) {
                return student1.getFirstName().compareTo(student2.getFirstName());
            }
        };

        // Sort the list using the custom comparator
        Collections.sort(studentList, firstNameComparator);

        // Now, studentList is sorted based on first names
    }

}

### Q2

Consider a class Person with two
attributes - String name and
List<String> degrees. How will you
make this class immutable. Ask what
are the advantanges of immutable
classes.

To make a class immutable in Java, you need to follow a few key principles:

1. Make all fields private: This ensures that the internal state of the object cannot be modified directly from outside the class.

2. Make the class final: Making the class final prevents it from being subclassed, which could potentially lead to changes in behavior.

3. Don't provide setter methods: Do not provide methods that allow external code to modify the internal state of the object.

4. Ensure that mutable objects are not exposed: If your class contains references to mutable objects (e.g., lists), make sure to return copies of these objects or use defensive copying to prevent modification.

Here's an example of how you can make the `Person` class immutable:

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public final class Person {
    private final String name;
    private final List<String> degrees;

    public Person(String name, List<String> degrees) {
        this.name = name;
        // Create a defensive copy of the list to ensure immutability
        this.degrees = new ArrayList<>(degrees);
    }

    public String getName() {
        return name;
    }

    // Provide a read-only view of the degrees list to prevent modification
    public List<String> getDegrees() {
        return Collections.unmodifiableList(degrees);
    }
}
```

Advantages of Immutable Classes:

1. **Thread Safety**: Immutable objects are inherently thread-safe because their state cannot be changed once they are created. This eliminates the need for synchronization in multithreaded environments.

2. **Simpler Code**: With immutability, you don't need to worry about complex state changes over time. This leads to simpler, more predictable code.

3. **Caching**: Immutable objects can be safely cached because you know they won't change. This can improve performance in certain scenarios.

4. **Security**: Immutable objects are less prone to security vulnerabilities because they can't be tampered with once created.

5. **Copy Safety**: Since you cannot modify an immutable object, there's no risk of accidentally changing its state.

6. **Hashing and Equality**: Immutable objects can use their state for hashing and equality comparisons, which simplifies these operations.

7. **Safe Sharing**: Immutable objects can be freely shared between different parts of your code or even different threads without the need for defensive copying.

By following the principles of immutability, you can create more robust and predictable code, particularly in multithreaded or distributed systems.

### Q3

Can one use an Employee class as a
key in a HashMap?

Yes, you can use an Employee class as a key in a HashMap in Java, but to do so, you need to ensure that the Employee class overrides the equals() and hashCode() methods correctly. These methods are crucial for the proper functioning of a HashMap when custom objects are used as keys.

Here's what you need to do:

Override equals() method: The equals() method should be overridden to compare two Employee objects based on the criteria you want to consider for equality. Typically, you would compare attributes such as the employee's ID or some other unique identifier.

Override hashCode() method: The hashCode() method should be overridden to provide a consistent hash code for each Employee object based on the same criteria used in the equals() method. The hash code is used to determine the bucket in which the key-value pair is stored in the HashMap.

import java.util.Objects;

public class Employee {
private int id;
private String name;

    public Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Employee employee = (Employee) o;
        return id == employee.id && Objects.equals(name, employee.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }

    // Other getters, setters, and methods...

}

With this implementation, you can use Employee objects as keys in a HashMap, and the equals() and hashCode() methods will ensure that keys are compared and hashed correctly based on the id and name attributes.

Here's an example of how you might use the Employee class as a key in a HashMap

import java.util.HashMap;
import java.util.Map;

public class Main {
public static void main(String[] args) {
Map<Employee, String> employeeMap = new HashMap<>();

        Employee emp1 = new Employee(1, "John");
        Employee emp2 = new Employee(2, "Jane");

        employeeMap.put(emp1, "Employee 1");
        employeeMap.put(emp2, "Employee 2");

        System.out.println(employeeMap.get(emp1)); // Outputs "Employee 1"
    }

}

### Q4

We have a Parent class with 2
methods walk and run. We have a
child class which overrides both the
methods. Both child class methods
just call their respective Super
implementation. Parent class run
method calls walk(). class Parent
Parent p = new Child(); p.run(); Tell
the order in which each method is called.

In this scenario, you have a parent class Parent with two methods, walk and run, and a child class Child that overrides both methods. The Parent class's run method calls the walk method. You create an instance of Child and assign it to a reference of type Parent, like this:

Parent p = new Child();
p.run();

Here's the order in which the methods will be called:

The run method of the Child class will be called because you've created an instance of Child and assigned it to the p reference. This is an example of polymorphism.

Inside the Child class's run method, it will call the super.run() method, which is the run method of the Parent class.

Inside the Parent class's run method, it will call the walk method.

So, the order of method calls will be: Child.run() -> Parent.run() -> Parent.walk().

### Q5

Given a List of integers
(List<Integer>), write code in Java 8
style to get the sum of the squares of
all the odd numbers in the array.

```java
import java.util.List;

public class Main {
public static void main(String[] args) {
List<Integer> numbers = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9);

        int sumOfSquaresOfOdds = numbers.stream()
                .filter(n -> n % 2 != 0)          // Filter odd numbers
                .mapToInt(n -> n * n)            // Square each number
                .sum();                          // Calculate the sum

        System.out.println("Sum of squares of odd numbers: " + sumOfSquaresOfOdds);
    }

}

OR

Integer oddSquareSum = numbers.stream()
                    .filter(n -> n % 2 != 0) // Keep only odd numbers
                    .map(n -> {
                        return n \* n; // Square each odd number
                    })
                    .reduce(0, (accumulator, currentValue) -> {
                        return accumulator + currentValue; // Add each squared number
                    });
```

### Q6

We have a table called BookAuthor.
It has two columns Book and Author,
Book being unique column. Write a
query to find the names of the authors
who have written more than 10
books.

SELECT Author
FROM BookAuthor
GROUP BY Author
HAVING COUNT(Book) > 10;

### Q7

Given an array of n integers and a
number k, find the pairs of numbers
in the array such that the difference
between the pair is k. Find the
optimal solution with and without
extra storage

Optimal Solution Without Extra Storage
Sort the array in ascending order.
Initialize two pointers, left and right, to the beginning and end of the sorted array, respectively.
Iterate through the array while left is less than right.
Calculate the difference between the elements at left and right.
If the difference is equal to k, you've found a valid pair.
If the difference is less than k, increment the right pointer to increase the difference.
If the difference is greater than k, increment the left pointer to decrease the difference.
Continue this process until left is less than right.
Here's a Java code example for this approach:

import java.util.Arrays;

public class FindPairsWithDifferenceK {
public static void findPairs(int[] arr, int k) {
Arrays.sort(arr);
int left = 0, right = 1;

        while (right < arr.length) {
            int diff = arr[right] - arr[left];

            if (diff == k) {
                System.out.println("(" + arr[left] + ", " + arr[right] + ")");
                left++;
                right++;
            } else if (diff < k) {
                right++;
            } else {
                left++;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 3, 4, 2};
        int k = 2;
        findPairs(arr, k);
    }

}

Optimal Solution With Extra Storage
You can use a HashSet to keep track of elements as you iterate through the array. For each element x in the array, check if x - k or x + k exists in the HashSet. If either exists, you've found a valid pair.

Here's a Java code example for this approach:

import java.util.HashSet;

public class FindPairsWithDifferenceK {
public static void findPairs(int[] arr, int k) {
HashSet<Integer> set = new HashSet<>();
for (int x : arr) {
if (set.contains(x - k)) {
System.out.println("(" + (x - k) + ", " + x + ")");
}
if (set.contains(x + k)) {
System.out.println("(" + x + ", " + (x + k) + ")");
}
set.add(x);
}
}

    public static void main(String[] args) {
        int[] arr = {1, 5, 3, 4, 2};
        int k = 2;
        findPairs(arr, k);
    }

}

### What is completableFuture?

CompletableFuture is used for asynchronous programming in java. Asynchronous programming is a means of writing non-blocking code by running a task on a separate thread than the main application thread and notifying the main thread about its progress, completion or failure.

### How to decide the thread pool size ?

1. CPU intensive tasks - number of threads are equal to number of cores
2. IO intensive tasks - we can have more number of threads in this scenario

### What will be the output of the following code segment

```java
public class Main{
    public static void main(String[] args){
        System.out.println(100+100+"Akshit"); //200Akshit
        System.out.println("Akshit" + 100 + 100);// Akshit100100
    }
}
```

this is because the jvm evaluates the expression from left. In the first case it sees 1st and 2nd value as integer so it adds them and then sees a string so appends them. In second case it sees string the first time so appends them, and at last since the result of the previous operation is string and current index points to integer it agains appends them.

### Define copy constructor in java?

A copy constructor in java is a constructor that initializes an object through another object of the same class.

### Define package in java ?

Package is a collective bundle of classes and interfaces along with necessary libraries and JAR files. The use of packages help in code resusability.

### Differentiate between instance variable and local variable

Instance variables are declared inside a class and the scope is limited only to a specific object.
Local variable can be anywhere inside a method, or a specific block of code. Also the scope is limited to the block of code where the variable is declared.

### Define late binding

Late binding means the method call is resolved at runtime, not at compile time.

```java
class Animal {
    void sound() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}

public class Test {
    public static void main(String[] args) {
        Animal a = new Dog(); // reference of parent, object of child
        a.sound(); // Output: Dog barks → resolved at runtime (late binding)
    }
}

```

### Give the briefing on the lifecycle of the thread

The lifecycle of the thread includes five stages as mentioned below.
New Born state
Runnable state
Running state
Blocked state
Dead state

### Explain Daemon Thread

The daemon thread can be defined as a thread with least priority. The daemon thread is designed to run in the background during the process of garbage collection in java. The setDaemon() method is used to create a daemon thread in java.

### finalize method has been deprecated after java 9

### Even though object class is extended by every class we can explicity extend the same as well using extends keyword

### Wrapper classes

Integer iref = new Integer(10); //boxing
int i = iref.intValue(); //unboxing
Integer iref2 = 10; //autoboxing

Converting the primitives into objects allows us to pass them by reference in java

### Stack vs Heap

```java
class Point{
    int x;
    int y;
    void showPoint(){
    }
}

class Main{
    public static void main(String[] args){
        Point pref = new Point();
        // in this case the reference for object is stored in stack and actual memory for the object is initialized in heap
    }
}
```

### Arraylist vs Vector

- ArrayList is not synchronozed while vector is synchronized, this makes arraylist faster than vector because it does not have synchronization overrhead.

### Difference b/w equals() && == operator

```java
String s = new String("akshit"); // s is a reference variable which is having reference of a object
String s2 = new String("akshit");// sane as above for s2

if(s == s2){ // here the references are being compared which are both different hence the resultant value will be false
    print("equals");
}else{
    print("not equals");
}

//output = not equals
//to compare objects we use equals which actually matches the object values.

        String s = new String("akshit"); // s is a reference variable which is having reference of a object
        String s2 = new String("akshit");// sane as above for s2

        if(s == s2){ // here the references are being compared which are both different hence the resultant value will be false
            System.out.println("equals");
        }else{
            System.out.println("not equals");
        }

        //op-  not equals

        String t1 = "temp";
        String t2 = "temp";
        if(t1 == t2){ // here the references are being compared which are both same hence the resultant value will be true
            System.out.println("equals");
        }else{
            System.out.println("not equals");
        }

        ////op-  equals
```

Yes, in this case, **two different objects** are created in the heap memory, and **two reference variables** (`s` and `s2`) are assigned to them.

### **Breakdown of Execution**

```java
String s = new String("akshit");
String s2 = new String("akshit");
```

1. **Heap Memory Allocation**:

   - `new String("akshit")` explicitly creates a new `String` object in the heap.
   - So, `s` refers to a new `String` object in the heap.
   - Similarly, `new String("akshit")` again creates **another separate** `String` object in the heap.
   - `s2` refers to this new `String` object.
   - Hence, **two different objects exist in the heap**, each containing `"akshit"`.

2. **String Pool Check**:
   - `"akshit"` is a **string literal**, so it is stored in the **String Pool** (if not already present).
   - Both `s` and `s2` **point to different objects** in the heap, **not** the String Pool.

### **Memory Diagram**

```
String Pool: ["akshit"]   <-- (Not used directly by s or s2)
Heap:
    [ "akshit" ]  <-- Referenced by s
    [ "akshit" ]  <-- Referenced by s2
```

### **Key Takeaways**

- **Two objects** are created in heap memory.
- **Two reference variables (`s` and `s2`) are created.**
- The string pool instance of `"akshit"` is **not** used directly in this case.

✅ If you want both variables to refer to the same object, use:

```java
String s = "akshit";  // Uses string pool
String s2 = "akshit"; // Points to same object in pool
System.out.println(s == s2); // true (same reference)
```

🚨 **But in your case**:

```java
System.out.println(s == s2); // false (different objects)
```

### in this case what happens in string pool, considering it was empty beforehand

String s = new String("akshit");
String s2 = new String("akshit");

Let's break it down step by step, assuming the **String Pool was initially empty**.

---

### **Step 1️⃣: `String s = new String("akshit");`**

- **First, `"akshit"` (a string literal) is encountered.**
  - Since the **String Pool was empty**, `"akshit"` gets added to the **String Pool**.
- **Then, `new String("akshit")` creates a separate object in the heap.**
  - The `new` keyword always creates a **new object in the heap**, even if the same string exists in the pool.

📌 **After this line:**

- **Heap Memory** → `new String("akshit")` (separate object)
- **String Pool** → `"akshit"`

```java
// Diagram:
Heap:   [ "akshit" (separate object) ]
Pool:   [ "akshit" ]
```

---

### **Step 2️⃣: `String s2 = new String("akshit");`**

- Again, `"akshit"` (literal) is encountered, but it's **already present in the pool**.
- **A new object is created in the heap**, just like before.

📌 **After this line:**

- **Heap Memory** → Two different `"akshit"` objects.
- **String Pool** → Still contains only **one** `"akshit"`.

```java
// Diagram:
Heap:   [ "akshit" (object 1) ]  [ "akshit" (object 2) ]
Pool:   [ "akshit" ]
```

---

### **Checking References**

```java
System.out.println(s == s2);   // false (different objects in heap)
System.out.println(s.equals(s2));   // true (same content)
```

- `s == s2` is **false** because both refer to **different objects in the heap**.
- `s.equals(s2)` is **true** because both have the same content.

---

### **How to Use the String Pool?**

If you want `s` and `s2` to refer to the same object in the pool, you should use **interning**:

```java
String s3 = new String("akshit").intern();
String s4 = new String("akshit").intern();
System.out.println(s3 == s4);  // true (both refer to pooled string)
```

- `.intern()` returns the reference from the **String Pool** instead of creating a new heap object.

---

### **🔹 Key Takeaways**

1. **String literals are stored in the String Pool automatically.**
2. **`new String("value")` always creates a new object in the heap.**
3. **The String Pool is not polluted with duplicate objects—only one copy exists.**
4. **Use `.intern()` to force a string to be stored in the pool.**

Let me know if you need more clarity! 🚀

### can we create private methods in java interface

In Java, interfaces are meant to declare abstract methods that provide a contract for classes to implement. Prior to Java 9, interfaces could only contain abstract method declarations and constants (public static final fields). Private methods were not allowed in interfaces.

However, starting from Java 9, you can include private methods in interfaces using the following two types:

1. **Private Instance Methods**: These are non-static private methods that can be used within default methods and other private methods in the same interface. They are useful for breaking down complex default methods into smaller, more manageable pieces.

   ```java
   interface MyInterface {
       default void publicMethod() {
           // This method can call privateMethod()
           privateMethod();
       }

       private void privateMethod() {
           // Private method implementation
       }
   }
   ```

2. **Private Static Methods**: These are private methods marked as `static`. They can be used within other methods (both static and instance) within the interface. These methods are typically used for utility functions shared among default methods.

   ```java
   interface MyInterface {
       default void publicMethod() {
           // This method can call privateStaticMethod()
           privateStaticMethod();
       }

       private static void privateStaticMethod() {
           // Private static method implementation
       }
   }
   ```

These private methods are not part of the contract exposed by the interface and cannot be accessed from classes that implement the interface. Their purpose is to help interface developers organize and reuse code within the interface itself without affecting implementing classes.

### can non static methods call static methods

Yes, non-static methods can call static methods in Java. Static methods belong to the class itself rather than instances of the class, so they can be called from both static and non-static (instance) methods within the same class. Here's an example:

```java
public class MyClass {
    public static void staticMethod() {
        System.out.println("Static method called");
    }

    public void nonStaticMethod() {
        System.out.println("Non-static method called");
        staticMethod(); // Calling the static method from a non-static method
    }

    public static void main(String[] args) {
        MyClass obj = new MyClass();
        obj.nonStaticMethod(); // Calling the non-static method
    }
}
```

In this example, the `staticMethod` is called from the `nonStaticMethod`, and it works perfectly fine. Static methods are associated with the class itself, so they don't require an instance of the class to be called. However, they can also be called using an instance of the class, as shown in the `main` method.

### Can't i declare static abstract methods ?

No, you **cannot** declare `static abstract` methods in Java.

### **Why?**

1. **Abstract methods require overriding**, but static methods **belong to the class itself** and are **not inherited** or **overridden** in the usual way.
2. If `static abstract` were allowed, the method would need to be overridden in subclasses, but since `static` methods **cannot be overridden (only hidden)**, it creates a contradiction.

---

### **Example that won't work**

```java
abstract class Example {
    abstract static void doSomething(); // ❌ Compilation Error
}
```

👉 **Error**: `Modifier 'abstract' not allowed here`

---

### **What Can You Do Instead?**

#### ✅ **Option 1: Provide a Default Implementation**

If you need a **static** method with default behavior in an abstract class:

```java
abstract class Example {
    static void doSomething() {
        System.out.println("Default implementation");
    }
}
```

👉 This can be called as `Example.doSomething();`, but subclasses **cannot** override it.

---

#### ✅ **Option 2: Use an Abstract Instance Method**

If you want subclasses to provide their own implementation:

```java
abstract class Example {
    abstract void doSomething(); // Subclasses must implement this
}
```

---

#### ✅ **Option 3: Use a Static Method in an Interface (Java 8+)**

Java 8 introduced **static methods in interfaces**, which act like utility methods.

```java
interface Example {
    static void doSomething() {
        System.out.println("Static method in interface");
    }
}
```

👉 Call it as `Example.doSomething();`, but it **cannot be overridden**.

---

### **Conclusion**

`static abstract` methods **are not allowed** because `abstract` implies **mandatory overriding**, while `static` methods **cannot be overridden**. If you need such behavior, consider **default implementations, abstract instance methods, or static methods in interfaces**. 🚀
