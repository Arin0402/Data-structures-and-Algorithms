### What are suppliers in java ?

In Java, a `Supplier` is a functional interface from the `java.util.function` package introduced in Java 8. It represents a supplier of results, meaning it defines a single abstract method that takes no arguments and returns a result. The primary purpose of a `Supplier` is to provide (or "supply") values or objects when needed, without any input.

The `Supplier` interface is defined as follows:

```java
T get();
```

Here, `T` is the type of the result that the supplier provides, and the `get` method takes no arguments and returns an object of type `T`.

`Suppliers` are often used in scenarios where you need to defer the computation or retrieval of a value until it is actually needed. Some common use cases for `Supplier` include:

1. **Lazy Initialization:** You can use a `Supplier` to initialize an object or value only when it's requested, rather than eagerly.

Here's a simple example of using a `Supplier` to perform lazy initialization:

```java
import java.util.function.Supplier;

public class SupplierExample {
    public static void main(String[] args) {
        // Define a Supplier for lazy initialization
        Supplier<String> lazyInit = () -> {
            System.out.println("Initializing...");
            return "Initialized Value";
        };

        // Use the Supplier to get the value (initialization happens here)
        System.out.println("Value: " + lazyInit.get());
        System.out.println("Value: " + lazyInit.get()); // No re-initialization occurs
    }
}
```

In this example, the `lazyInit` supplier initializes the value only when the `get()` method is called. Subsequent calls to `get()` do not trigger re-initialization; instead, the cached result is returned.

`Suppliers` are useful for improving efficiency, reducing unnecessary computations, and providing a clean way to encapsulate the retrieval or generation of values in a lazy or deferred manner.
