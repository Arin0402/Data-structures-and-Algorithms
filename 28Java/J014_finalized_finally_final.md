In Java, "finalized," "finally," and "final" are related terms, but they serve different purposes in the language:

1. **`finalize`**:

   - `finalize()` is a method that is automatically called by the Java Garbage Collector (GC) when it determines that there are no more references to an object and it's about to be reclaimed.
   - You can override the `finalize()` method in your classes to perform cleanup or resource release before an object is garbage collected. However, it's considered a best practice to use other mechanisms for resource management in modern Java, like try-with-resources for handling resources like files, streams, and sockets.

   Example of `finalize()` method:

   ```java
   public class MyClass {
       // Constructor and other methods...

       @Override
       protected void finalize() throws Throwable {
           // Perform cleanup before the object is garbage collected
           // This method is called automatically by the GC
       }
   }
   ```

2. **`finally`**:

   - `finally` is a keyword in Java used in exception handling.
   - It's used in a `try-catch-finally` block to define a block of code that always gets executed, whether an exception is thrown or not. This is useful for releasing resources or performing cleanup operations. Like releasing database connections once done with them.

   Example of `finally` block:

   ```java
   try {
       // Code that might throw an exception
   } catch (Exception e) {
       // Handle the exception
   } finally {
       // Code in this block always executes, even if there was an exception
       // Perform cleanup or resource release here
   }
   ```

3. **`final`**:

   - `final` is a keyword in Java used to declare that a class, method, variable, or parameter is not subject to modification, extension, or overriding.
   - When applied to a class, it indicates that the class cannot be subclassed.
   - When applied to a method, it indicates that the method cannot be overridden by subclasses.
   - When applied to a variable, it indicates that the variable is a constant and cannot be reassigned.
   - When applied to a parameter, it indicates that the parameter cannot be modified within the method.

   Examples of `final`:

   ```java
   final class MyFinalClass { // Cannot be subclassed
       // ...
   }

   class Parent {
       final void doSomething() { // Cannot be overridden by subclasses
           // ...
       }
   }

   class Child extends Parent {
       // This would be a compilation error
       // void doSomething() { /* ... */ }
   }

   void myMethod(final int x) { // x cannot be modified within the method
       // ...
   }

   final int MY_CONSTANT = 42; // Constant variable
   ```

In summary, `finalize()` is a method for performing cleanup during garbage collection, `finally` is a keyword used in exception handling for cleanup code, and `final` is a keyword used to indicate that something cannot be modified, extended, or overridden.

### Exception hierarchy in inheritance

if a parent method throws exception it is not necessary for the overriden method to throw the same but if you want overriden method to throw the exception then in that case we need to add throwing code to parent signature as well otherwise this throws compilation error,

### Compile time vs runtime exceptions

### ✅ **1. Compile-Time Exception (Checked Exception)**

#### 🔹 Definition:

- Detected **by the compiler**.
- Must be **handled with `try-catch`** or declared with `throws`.

#### 🔹 Examples:

- `IOException`
- `SQLException`
- `FileNotFoundException`

#### 🧪 Code Example:

```java
import java.io.*;

public class TestChecked {
    public static void main(String[] args) {
        try {
            FileReader file = new FileReader("test.txt"); // Might throw FileNotFoundException
        } catch (FileNotFoundException e) {
            System.out.println("File not found!");
        }
    }
}
```

---

### ✅ **2. Run-Time Exception (Unchecked Exception)**

#### 🔹 Definition:

- Detected **while the program is running**.
- **No compiler error**, but may crash at runtime.
- Usually due to **logic or programming errors**.

#### 🔹 Examples:

- `NullPointerException`
- `ArithmeticException`
- `ArrayIndexOutOfBoundsException`

#### 🧪 Code Example:

```java
public class TestUnchecked {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        System.out.println(arr[5]); // ArrayIndexOutOfBoundsException

        String str = null;
        System.out.println(str.length()); // NullPointerException
    }
}
```

### How to create your custom exception

```java
public class OrderNotFoundException extends Exception{
    public OrderNotFoundException(String message){
        super(message);
    }
}

public class Test{
    public void getOrder(int orderId){
        if(orderId == 101) throw new OrderNotFoundException("101 order id not found");
    }
}

```
