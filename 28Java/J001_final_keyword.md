### what is the use of final keyword in java

The final keyword in Java is used to indicate that a variable, method, or class cannot be changed or overridden.

Here are the main uses of the final keyword:

1.  Final Variables: When applied to a variable, the final keyword indicates that its value cannot be modified once assigned. This is useful when you want to create constants or ensure that a variable remains constant throughout its lifetime.

    final int MAX_VALUE = 100;

2.  Final Methods: When applied to a method, the final keyword indicates that the method cannot be overridden by subclasses. This is useful when you want to prevent the method's behavior from being modified by subclasses.

    public class ParentClass {
    public final void finalMethod() {
    // Method implementation
    }
    }

    public class ChildClass extends ParentClass {
    // This will result in a compile-time error
    // as finalMethod() cannot be overridden
    }

3.  Final Classes: When applied to a class, the final keyword indicates that the class cannot be subclassed. This is useful when you want to prevent the class's behavior from being extended or modified.

    public final class FinalClass {
    // Class implementation
    }

    // This will result in a compile-time error
    // as FinalClass cannot be subclassed
    public class Subclass extends FinalClass {
    // Class implementation
    }

### Why do we need a final class ?

In Java, the final keyword can be used to define a class as final. A final class is a class that cannot be subclassed, meaning it cannot be extended by other classes. There are several reasons why you might choose to make a class final:

1. Preventing inheritance: By making a class final, you explicitly state that the class is complete and should not be extended.

2. Security considerations: Final classes can provide security benefits by preventing sensitive classes from being overridden or tampered with by malicious subclasses. This can be particularly important in certain security-critical scenarios.

3. Performance optimizations: The compiler and runtime environment can make certain optimizations based on the knowledge that a class is final. This includes inlining methods, caching values, or eliminating unnecessary checks, resulting in potential performance improvements.

4. Design intent and clarity: Marking a class as final can communicate the design intent and make the class's purpose and limitations clear to other developers who may work with or extend the codebase. It can serve as a form of documentation to express that the class is not intended to be extended.

### Example of already present final classes in java ?

In Java, there are several built-in classes that are declared as final by the Java platform. Here are a few examples:

1. String class: The String class in Java is immutable and declared as final. It represents a sequence of characters and is widely used for string manipulation.

2. Integer, Double, and other wrapper classes: The wrapper classes for primitive types, such as Integer, Double, Boolean, etc., are also declared as final. These classes provide methods and functionality to work with their respective primitive types.

3. Math class: The Math class in Java provides various mathematical operations and constants. It is declared as final and cannot be subclassed.

4. System class: The System class contains methods and properties related to the system, such as input/output streams, environment variables, etc. It is declared as final to prevent subclassing and to maintain system integrity.

5. Runtime class: The Runtime class provides an interface to the Java runtime system. It allows interaction with the operating system environment and provides methods to manage processes and system resources. It is declared as final and cannot be subclassed.

### Give a scenario where final classes would be beneficial

One scenario where a final class can be beneficial is when designing utility classes or classes that provide critical functionality and should not be extended or modified. Here's an example:

public final class MathUtils {
private MathUtils() {
// private constructor to prevent instantiation
}

    public static int add(int a, int b) {
        return a + b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }

}

In the example above, we have a MathUtils class that provides utility methods for mathematical operations. The class is declared as final to prevent subclassing. It also has a private constructor to prevent instantiation, as the class is intended to be used statically.

By making the MathUtils class final, we ensure that the class's behavior and implementation remain consistent across different usages. Subclassing could potentially introduce unintended behaviors or override critical methods, which may lead to unexpected results.
