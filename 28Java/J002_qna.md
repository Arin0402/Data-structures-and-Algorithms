### Why java is not 100% object-oriented

Java is often considered to be predominantly object-oriented, but it is not considered 100% pure or completely object-oriented for a few reasons:

Primitive Data Types: Java includes primitive data types such as int, char, boolean, etc., which are not objects. These types do not have associated methods or inheritance hierarchies like objects do. However, Java provides wrapper classes (e.g., Integer, Character, Boolean) to allow these primitive types to be used as objects when necessary.

Static Members: Java allows the declaration of static variables and methods at the class level. Static members are associated with the class itself rather than with individual instances of the class. They can be accessed without creating objects and are not part of the object's state. This deviates from the core principles of object-oriented programming, which focus on encapsulating behavior within objects.

ex - pure objecy oriented - ruby, scala

### What methods does object class have ?

It has following methods(CEFGHT)

- clone()
- equals();
- finalize(); called by garbage collector on an object when garbagecollection determines that there are no more references to the object.
- getClass()
- hashCode()
- toString()

### How can you make a class immutable in java ?

To make a class immutable in Java, you need to follow a few guidelines:

1. Make the class final: This ensures that the class cannot be subclassed and its behavior cannot be altered.

2. Make all fields private and final: Private access ensures that the fields cannot be accessed directly from outside the class, and final ensures that their values cannot be changed once initialized.

3. Do not provide any setter methods: Since the fields are final, they cannot be modified after object creation. Therefore, you should not provide any setter methods that would allow changing the state of the object.

4. Ensure that mutable objects are not exposed: If the class has fields referring to mutable objects, make sure to return defensive copies or immutable views of those objects instead of returning the original references. This prevents external modification of the class's state. If you need to provide access to the class's fields, create getter methods that return the values of the fields. However, ensure that the returned values are either primitives or immutable objects to prevent modification.

```java
public final class ImmutableClass {
    private final int immutableField;
    private final String immutableString;
    private final List<String> mutableList;

    public ImmutableClass(int field, String string, List<String> list) {
        this.immutableField = field;
        this.immutableString = string;
        this.mutableList = new ArrayList<>(list);
    }

    public int getImmutableField() {
        return immutableField;
    }

    public String getImmutableString() {
        return immutableString;
    }

    public List<String> getMutableList() {
        return Collections.unmodifiableList(mutableList);
    }

}
```

- we can create an object of java immutable classes

#### can private methods be overridden in subclasses?

No, private methods cannot be overridden in subclasses in Java.

When a method is declared as private, it is not accessible to subclasses. Subclasses cannot see or access private methods, so there is no possibility of overriding them.

    public class ParentClass {
        private void privateMethod() {
            System.out.println("Parent's private method");
        }

        public void publicMethod() {
            privateMethod();
        }
    }

    public class ChildClass extends ParentClass {
        // This is not an override, but a separate method with the same name
        private void privateMethod() {
            System.out.println("Child's private method");
        }
    }

    public class Main {
        public static void main(String[] args) {
            ChildClass childObj = new ChildClass();
            childObj.publicMethod();  // Output: Parent's private method
        }
    }

### then why use final for final method when private methods itself cannot be overriden ?

you're correct that private methods cannot be overridden in subclasses, regardless of whether they are marked as final or not. In Java, marking a private method as final does not provide any additional functionality or restriction.

The final keyword is generally used to prevent method overriding in subclasses. It is useful when applied to public or protected methods, which can be accessed and overridden by subclasses. By marking a method as final, you explicitly indicate that the method's behavior should not be modified in any subclass.

However placing final keyword with private methods does not create any compilation error.

### We cannot access private methods using object, but we can access the protected methods under the same package using an object of any class.

### Abstract class in java

In Java, an abstract class is a class that cannot be instantiated directly but serves as a base for other classes. It is declared using the abstract keyword. An abstract class can contain abstract methods, concrete methods, instance variables, and constructors.

Here are some key characteristics and uses of abstract classes in Java:

Abstract Methods: An abstract class can have abstract methods, which are declared without an implementation. These methods are meant to be overridden by the subclasses. Subclasses must provide the implementation for all the abstract methods inherited from the abstract class. Abstract methods are declared using the abstract keyword and do not have a body.

Concrete Methods: In addition to abstract methods, an abstract class can also have concrete (non-abstract) methods. These methods provide a default implementation and can be directly invoked or overridden by the subclasses. Concrete methods in an abstract class are fully implemented and contain the method body.

Inheritance: Subclasses extend the abstract class using the extends keyword. They inherit the abstract methods and concrete methods from the abstract class.

#### Subclasses must either provide the implementation for all the abstract methods or be declared as abstract themselves.

Cannot be Instantiated: Abstract classes cannot be directly instantiated using the new keyword. This is because abstract classes are incomplete and meant to be extended by subclasses. To use an abstract class, you need to create a subclass that provides the implementation for all the abstract methods.

Here's an example of an abstract class and its subclass:

```java
abstract class Shape {
protected String color;

    public Shape(String color) {
        this.color = color;
    }

    public abstract double calculateArea();

    public void display() {
        System.out.println("This is a " + color + " shape.");
    }

}

class Circle extends Shape {
private double radius;

    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

}

public class Main {
public static void main(String[] args) {
Circle circle = new Circle("Red", 5.0);
circle.display();
System.out.println("Area: " + circle.calculateArea());
}
}
```

In this example, Shape is an abstract class that has an abstract method calculateArea() and a concrete method display(). The Circle class extends Shape and provides the implementation for the calculateArea() method. The Main class demonstrates the usage of the Circle class.

### can a class be both abstract and final ?

No, in Java, a class cannot be both abstract and final at the same time. These keywords have conflicting purposes and behaviors.

The abstract keyword is used to indicate that a class is incomplete and must be extended by subclasses. It allows the class to have abstract methods that are meant to be overridden by the subclasses. An abstract class cannot be instantiated directly; it serves as a blueprint for creating concrete subclasses.

On the other hand, the final keyword is used to indicate that a class cannot be subclassed. It prevents other classes from extending it and altering its behavior. Once a class is marked as final, it cannot have any subclasses.

Since the abstract keyword encourages extension and the final keyword prohibits extension, they cannot be used together on the same class. It would be contradictory to mark a class as abstract and final simultaneously.

Here's an example to illustrate the conflicting use of abstract and final:
public abstract final class AbstractFinalClass {
// Class implementation
}
In the example above, the class AbstractFinalClass is marked as both abstract and final. This will result in a compilation error because the two keywords cannot be used together on the same class.

### how to make a static class

In Java, you cannot directly declare a class as "static." However, you can create a nested class that is declared as static. This nested class is commonly known as a "static nested class" or a "static inner class."

Here's an example of how to create a static nested class:

```java
public class OuterClass {
    public static class StaticNestedClass {
        // Static nested class members and methods
    }
}
```

In the example above, StaticNestedClass is a static nested class within the OuterClass. To access the static nested class, you don't need to create an instance of the outer class. You can access it using the outer class name followed by the static nested class name:

OuterClass.StaticNestedClass nestedObj = new OuterClass.StaticNestedClass();

Static nested classes have the following characteristics:

They can have both static and non-static members, including fields, methods, and nested classes.
They can access static members of the outer class, but they cannot access non-static members directly. To access non-static members of the outer class, you need an instance of the outer class.

They can be public, private, protected, or have default (package-private) access, just like any other class.

If a class is only useful to its enclosing class, nesting it helps keep code organized and encapsulated. For Example in Android Adapters, the ViewHolder classes are mostly nested because they do not have any use outside the adapter.

### What is a singleton class in Java, how can we make a class singleton ?

Singleton class is a class whose only one instance can be created at any given time, in one JVM :

public class Animal {
private static Animal single_instance = null; // Fixed 'statict' typo

    private Animal() {
        // Private constructor to prevent instantiation
    }

    public static Animal getInstance() {
        if (single_instance == null) {
            single_instance = new Animal();
        }
        return single_instance;
    }

}

### What is the use of private Constructor in java ?

A **private constructor** in Java is used to **restrict instantiation** of a class from outside.

### ✅ Common uses:

- **Singleton pattern** – ensures only one instance exists.
- **Utility classes** – prevent creating objects (e.g., `Math`, `Collections`).

```java
private ClassName() {
  // Prevent instantiation
}
```

### Why pointers are not used in java ?

They are unsafe
Increases the complexity of the program and since java is known for its simplicity of code, adding the concepts of the pointers will be contradicting
Since JVM is responsible for implicit memory allocation, thus in order to avoid direcrt access to memory by the user, pointers are discouraged in java

### What is Java ByteCode

Java bytecode is the **intermediate, platform-independent code** generated by the Java compiler (`.class` files).

It is executed by the **Java Virtual Machine (JVM)**, which converts it into **machine-specific instructions** at runtime.

### ✅ Key Points:

- Written once, run anywhere (WORA).
- Stored in `.class` files.
- Enables Java’s portability and security.

### How to compile a file

To compile a Java file, use the `javac` command in the terminal or command prompt.

### ✅ Syntax:

```bash
javac FileName.java
```

### 📌 Example:

```bash
javac HelloWorld.java
```

This creates a `HelloWorld.class` file (Java bytecode) in the same directory.

To run the compiled class:

```bash
java HelloWorld
```

Let me know if your file is in a package or uses dependencies — steps vary slightly.

### What is JIT compiler in java

The **JIT (Just-In-Time) compiler** in Java is a part of the **Java Virtual Machine (JVM)** that improves performance by compiling **bytecode into native machine code at runtime**. The primary purpose of the JIT compiler is to improve the performance of Java applications by optimizing the execution of bytecode.

### ✅ Key Points:

- Runs after bytecode is loaded by the JVM.
- Converts **hot code paths** (frequently used) into native code.
- Speeds up execution by avoiding repeated interpretation.
- Works alongside the interpreter for optimized performance.

In short, **JIT makes Java faster** by compiling and caching native code during program execution.

By dynamically compiling bytecode into native machine code, the JIT compiler bridges the performance gap between interpreted languages and native compiled languages. It allows Java applications to achieve high-performance execution comparable to that of natively compiled languages while retaining the benefits of platform independence and automatic memory management provided by the JVM.

### 🔹 **How JIT Compilation Works**

1. **Java Source Code → Bytecode**

   - Java code is first compiled by the **Java Compiler (javac)** into **bytecode (.class files)**.
   - Bytecode is an intermediate representation, not tied to any specific hardware.

2. **Bytecode Execution in JVM**

   - The JVM **interprets** bytecode line by line initially, which is slower than compiled languages.

3. **JIT Compilation Kicks In**
   - The **JIT compiler** identifies **frequently executed code (hot spots)** and compiles it **just in time** into **native machine code**.
   - This native code is then **directly executed** by the CPU, skipping the interpretation step.
   - The JVM caches this compiled code for future use, improving performance.

### 🔹 **JIT vs. Ahead-of-Time (AOT) Compilation**

| Feature          | JIT Compilation (Java)                     | AOT Compilation (C, C++) |
| ---------------- | ------------------------------------------ | ------------------------ |
| Compilation Time | At runtime (on demand)                     | Before execution         |
| Optimization     | Adaptive, based on runtime behavior        | Fixed at compile time    |
| Startup Speed    | Slower (initial interpretation)            | Faster (precompiled)     |
| Execution Speed  | Can match native performance after warm-up | High from the start      |

### **Summary**

🚀 **JIT bridges the gap** between interpreted languages (like Python) and compiled languages (like C++) by compiling Java bytecode into native machine code at runtime.  
⚡ This results in **high performance**, **platform independence**, and **efficient memory management**—all key advantages of Java!

### why use interpreter then ?

Great question! If the **JIT compiler** gives better performance by converting bytecode to native machine code, then **why use the interpreter at all**?

Here’s why:

---

### 💡 **1. Faster Startup Time**

- When a Java program starts, the **interpreter kicks in immediately** and begins executing code line by line.
- If JVM waited for the JIT to compile everything first, startup would be **noticeably slower**.
- Interpretation allows **quick launch** of the application.

---

### 🔥 **2. JIT is Selective**

- **Not all code needs to be optimized.**
- The JIT only compiles **hot paths** (code that runs frequently).
- Interpreted execution is used for code that runs **infrequently**, where JIT overhead isn't worth it.
- JIT compilation consumes **CPU and memory**.
- For short-lived programs or rarely-used branches of code, compiling everything would **waste resources**.
- The interpreter helps **balance performance and resource use**.

---

### 🧪 **Profiling Before Compiling**

- JVM uses the interpreter to **profile** the code during execution.
- It gathers stats to decide what should be optimized by JIT.
- Without this warm-up period via interpretation, **JIT wouldn't know where to focus**.

### Why string is immutable in java ?

In Java, the String class is designed to be immutable, meaning that once a String object is created, its state (the sequence of characters it represents) cannot be changed. This immutability is intentional and has several important benefits:

1. Security: Strings are used in critical areas like file paths, database URLs, and network connections. If they were mutable, they could be modified after validation, leading to security risks.

2. Thread Safety: Since the value of a string can’t change, it can be shared across threads safely without synchronization.

3. Caching: Because strings are immutable, the JVM can safely reuse them. It keeps a pool of common string values, so when the same string is used again (like a literal), it doesn't create a new object. This is called string interning, and it helps save memory and improve performance.

4. Hashing and Key Usage: The immutability of strings makes them suitable for use as keys in hash-based data structures like HashMap or HashSet. Since the hash value of an object should remain constant during its lifetime, an immutable string provides a reliable and consistent hash value, ensuring proper functioning of hash-based collections.

### what is marker interface ?

A marker interface in Java is an interface with no methods or fields. It is used to tag a class to say it has a certain property or behavior.

By implementing it, a class tells the compiler or JVM that it should be treated in a special way — even though the interface itself does nothing.

🧠 Example: Serializable is a marker interface that tells Java a class can be saved or sent over a network.
Cloneable is a marker interface in java.lang that tells the JVM a class is allowed to be cloned using the Object.clone() method.

```java

public interface MarkerInterface {
// Empty marker interface
}

public class MyClass implements MarkerInterface {
// Class implementation
}
```

### Can you override a private or static method in java ?

No, private methods cannot be overriden but we can create a copy with same method name in the subclass.
Static methods are not overridden; they are hidden in subclasses if you declare a method with the same name and parameters.
You can call a static method using the class name or reference to a subclass, and the method in the class or subclass will be invoked accordingly.

###

```java
class Parent {
    static void show() {
        System.out.println("Parent");
    }
}

class Child extends Parent {
    static void show() {
        System.out.println("Child");
    }
}

public class Test {
    public static void main(String[] args) {
        Parent p = new Parent();
        Child c = new Child();
        Parent pc = new Child();

        p.show();   // Output: Parent
        c.show();   // Output: Child
        pc.show();  // Output: Parent (because method is static and resolved by reference type)
    }
}
```

### ✅ **Why does `object.show()` work if `show()` is static?**

Even though **static methods belong to the class**, **Java allows you to call them using an object reference** — **but it’s just syntax**, not real object-oriented behavior.

---

### 🔍 What's really happening:

```java
Parent obj = new Parent();
obj.show(); // ✅ This works, but it's not recommended
```

- Even though you're using `obj`, Java **resolves the call using the reference type** (`Parent`) **at compile time**.
- So this is **exactly the same** as writing:

  ```java
  Parent.show();
  ```

> The method call is **bound to the class**, not the object.

---

### ⚠️ Why it's **allowed** (but not recommended):

Java allows this for **convenience**, but it's misleading — because it **looks like polymorphism**, but it’s **not**.

That’s why **best practice** is:

> 🔒 Always call static methods using the **class name**, not the object reference.

---

### ✅ Summary:

| Concept                       | Explanation                               |
| ----------------------------- | ----------------------------------------- |
| Static method call via object | Allowed by Java, resolved at compile-time |
| Polymorphism?                 | ❌ No — static methods don't support it   |
| Best practice                 | ✅ Use class name to call static methods  |

---

Let me know if you want a quick example comparing this with instance method behavior!

### Does finally always execute in java ?

Not in following cases

1. system.exit()
2. system.crash

### Collection hierarchy in java ?

Here’s a clear breakdown of the **Java Collection hierarchy** — an important part of the Java Collections Framework (JCF), introduced in `java.util`.

---

### ✅ **Java Collection Hierarchy Overview**

```
java.util
└── Iterable (interface)
    └── Collection (interface)
        ├── List (interface)
        │   ├── ArrayList
        │   ├── LinkedList
        │   └── Vector
        │       └── Stack
        │
        ├── Set (interface)
        │   ├── HashSet
        │   │   └── LinkedHashSet
        │   └── TreeSet (SortedSet, NavigableSet)
        │
        └── Queue (interface)
            ├── LinkedList
            ├── PriorityQueue
            └── ArrayDeque
```

---

### 🔧 **Map is NOT a subtype of Collection**

Although part of the Java Collections Framework, `Map` is separate:

```
Map (interface)
├── HashMap
│   └── LinkedHashMap
├── TreeMap (SortedMap, NavigableMap)
└── Hashtable
    └── Properties
```

---

### ✅ Interface Summary:

| Interface | Description                | Examples                      |
| --------- | -------------------------- | ----------------------------- |
| `List`    | Ordered, allows duplicates | `ArrayList`, `LinkedList`     |
| `Set`     | Unordered, no duplicates   | `HashSet`, `TreeSet`          |
| `Queue`   | FIFO (mostly), ordered     | `PriorityQueue`, `ArrayDeque` |
| `Map`     | Key-value pairs            | `HashMap`, `TreeMap`          |

---

### 📌 Tip:

- Use `List` when **order matters**.
- Use `Set` when you need **uniqueness**.
- Use `Queue` for **FIFO** or **priority-based** access.
- Use `Map` to store data in **key-value** pairs.

Let me know if you want a visual diagram or real-world analogy!

### Difference between list and ArrayList

List is an interface, and ArrayList is a class that implements the List interface using a dynamic array.
You use List for flexibility, and ArrayList to create a list object.

### What is a deque ?

extends queue and is just a doubly linked list.

### Why map does not extend the collection interface ?

Map stores key-value pairs, while Collection is for single elements.
Their structures and behaviors are fundamentally different, so Map is kept separate.
Collection → holds: [1, 2, 3]
Map → holds: {a=1, b=2, c=3}

### 🔹 **4. `Map` Is Still Part of `Java.util` Framework**

Although `Map` does not extend `Collection`, it is still a part of the **Java Collections Framework** and works alongside `Collection` types.

For example:

```java
Map<Integer, String> map = new HashMap<>();
Set<Integer> keys = map.keySet();    // Returns a Set (Collection)
Collection<String> values = map.values();  // Returns a Collection of values
Set<Map.Entry<Integer, String>> entries = map.entrySet();  // Returns a Set of key-value pairs
```

This allows `Map` to be **used with collections indirectly** without forcing it to extend `Collection`.

### Access Control Modifiers

Java provides a number of access modifiers to set access levels for classes, variables, methods and constructors. The four access levels are −

Visible to the package, the default. No modifiers are needed.
Visible to the class only (private).
Visible to the world (public).
Visible to the package and all subclasses (protected). . Let us say in Package 'A' a base class has a protected method. One can access this protected method of base class in this package only. And If we have a childClass in Package 'B' we still can increase scope of base class protected method by extending it.

### what is the use of synchronized keyword in java

The synchronized keyword in Java is used to provide thread-safe access to shared resources or critical sections of code. It ensures that only one thread can execute the synchronized block or method at a time, preventing concurrent access and potential data inconsistencies.

public class Counter {
private int count;

    public synchronized void increment() {
        count++;
    }

    public synchronized int getCount() {
        return count;
    }

}

In the example above, the increment() and getCount() methods of the Counter class are declared as synchronized. This ensures that only one thread can access these methods at a time, preventing concurrent modifications or inconsistent reads of the count variable.

The synchronized keyword can be applied to methods, code blocks, and even static methods or blocks to achieve synchronization in Java. It plays a crucial role in concurrent programming and helps maintain thread safety and data consistency in multi-threaded environments.

### difference between protected and default keywords in java

In Java, both protected and default (package-private) access modifiers control the visibility and accessibility of members (methods, fields, and nested classes) within a class and among classes in the same package. However, there are differences in their visibility scopes. Here's a breakdown of the differences between protected and default access:

Default (Package-Private) Access:

    Visibility: Default access is the absence of an access modifier keyword. It allows members to be accessed within the same package only. Members with default access are not visible to classes outside the package.
    Inheritance: Default members are inherited by subclasses that are part of the same package.

Protected Access:

    Visibility: Protected access allows members to be accessed within the same package. An object of a class having protected methods can access those protected methods if the object was created within the same package.
    Inheritance: Protected members are inherited by subclasses, regardless of whether they are in the same package or a different package.

### how many classes can i create in a single file in java ?

In Java, you can have at most one public class per source file, and the source file name must match the name of the public class. However, you can have multiple non-public (package-private) classes in the same source file.

### is it compulsary to have a public class in a javas file ?

> **No, it's not compulsory** to have a `public` class in a Java file.

### ✅ But if you do have a `public` class:

- The **file name must match** the `public` class name.

  **Example:**

  ```java
  public class HelloWorld { }
  ```

### ✅ You can also have:

- A Java file with **no public class**
- A Java file with **multiple classes**, but **only one can be public**

### 🧠 Summary:

- ✔ Public class → file name **must match**
- ❌ Not required to have a public class in every `.java` file

Let me know if you want a code example!

## can a class be private in java ?

No, a top-level class (a class declared directly within a Java source file) cannot have the private access modifier in Java. The private access modifier is not allowed for top-level classes.

### ✅ Allowed Access Modifiers for **Top-Level Classes** in Java:

1. **`public`** – Class is accessible from **anywhere**.
2. **_default (package-private)_** – If no modifier is specified, class is accessible **only within the same package**.

```java
// public class
public class MyClass { }

// default (package-private) class
class MyOtherClass { }
```

---

### ❌ Not Allowed for Top-Level Classes:

- `private` ❌
- `protected` ❌
- `static` ❌ (only allowed for **nested classes**)

---

### ✅ Summary:

| Modifier    | Allowed for Top-Level Class? | Access Level            |
| ----------- | ---------------------------- | ----------------------- |
| `public`    | ✅ Yes                       | Everywhere              |
| _(default)_ | ✅ Yes                       | Same package only       |
| `private`   | ❌ No                        | Not allowed             |
| `protected` | ❌ No                        | Not allowed             |
| `static`    | ❌ No                        | Only for nested classes |

Let me know if you want rules for **inner/nested classes** too!

## Inner Classes (Non-static Nested Classes)

Inner classes are a security mechanism in Java. We know a class cannot be associated with the access modifier private, but if we have the class as a member of other class, then the inner class can be made private. And this is also used to access the private members of a class.

Creating an inner class is quite simple. You just need to write a class within a class. Unlike a class, an inner class can be private and once you declare an inner class private, it cannot be accessed from an object outside the class.

Following is the program to create an inner class and access it. In the given example, we make the inner class private and access the class through a method.

Example

Live Demo
class Outer_Demo {
int num;

// inner class
private class Inner_Demo {
public void print() {
System.out.println("This is an inner class");
}
}

// Accessing he inner class from the method within
void display_Inner() {
Inner_Demo inner = new Inner_Demo();
inner.print();
}
}

public class My_class {

public static void main(String args[]) {
// Instantiating the outer class
Outer_Demo outer = new Outer_Demo();

      // Accessing the display_Inner() method.
      outer.display_Inner();

}
}

### Types of inheritance

1. Single inheritance
2. Multi Level inheritance
3. Hierarchical inheritance
4. Multiple inheritance - java does not supports this - only one extends keyword is available

## A method declared final cannot be overridden.

## A method declared static cannot be overridden but can be re-declared.

## Constructors cannot be overridden.

class Animal {
public void move() {
System.out.println("Animals can move");
}
}

class Dog extends Animal {
public void move() {
super.move(); // invokes the super class method
System.out.println("Dogs can walk and run");
}
}

public class TestDog {

public static void main(String args[]) {
Animal b = new Dog(); // Animal reference but Dog object
b.move(); // runs the method in Dog class
}
}

### Can we create private abstract method in java ?

No, it is not possible to create a private abstract method in Java. The private access modifier restricts the visibility of a method to the same class in which it is declared. On the other hand, an abstract method is meant to be overridden and implemented in a subclass.

### Does java provide an empty constructor by default ?

Yes, Java classes have an empty constructor by default if no other constructor is explicitly defined. This default constructor, also known as the no-argument constructor, takes no parameters and initializes instance variables with their default values (e.g., 0 for integers, null for objects). If a constructor with arguments is defined, the default constructor is not automatically provided.
