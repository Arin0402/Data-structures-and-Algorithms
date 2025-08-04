Java 8 introduced several significant features and improvements to the Java programming language. Some of the key changes and features introduced in Java 8 include:

1. **Lambda Expressions**: Lambda expressions allow you to express instances of single-method interfaces (functional interfaces) using a shorter, more concise syntax. This is particularly useful for defining inline implementations of functional interfaces, making code more readable and expressive.

   ```java
   // Before Java 8
   Runnable runnable = new Runnable() {
       @Override
       public void run() {
           System.out.println("Hello, world!");
       }
   };

   // Java 8 and later with lambda
   Runnable runnable = () -> System.out.println("Hello, world!");
   ```

2. **Streams API**: The Streams API provides a powerful way to work with sequences of elements in a functional style. It allows you to perform operations like filter, map, reduce, and collect on collections and other data sources. Streams can significantly simplify and enhance the processing of data.

   ```java
   List<String> names = Arrays.asList("Alice", "Bob", "Charlie");
   List<String> filteredNames = names.stream()
                                     .filter(name -> name.length() > 4)
                                     .collect(Collectors.toList());
   ```

3. **Default Methods**: Interfaces can now have default method implementations. This feature allows you to add methods to existing interfaces without breaking compatibility with classes that already implement those interfaces.

   ```java
   interface MyInterface {
       void doSomething();

       default void doSomethingElse() {
           // Default implementation
       }
   }
   ```

   ```

   ```

4. **New Date and Time API**: Java 8 introduced the `java.time` package, which provides a modern date and time API with improved support for handling dates, times, durations, and time zones. It addresses many issues with the old `Date` and `Calendar` classes.

   ```java
   LocalDate today = LocalDate.now();
   ```

5. **Nashorn JavaScript Engine**: Java 8 includes the Nashorn JavaScript engine, which allows you to execute JavaScript code from Java applications. This is useful for embedding JavaScript in Java applications and for server-side scripting.

   ```java
   ScriptEngine engine = new ScriptEngineManager().getEngineByName("nashorn");
   engine.eval("print('Hello, world!')");
   ```

6. **Improved Concurrency**: Java 8 introduced the `CompletableFuture` class, which simplifies asynchronous programming and provides better support for managing and composing asynchronous tasks. The `java.util.concurrent` package also received enhancements.

7. **New API Additions**: Java 8 added various new classes and methods to the Java API, including the `Optional` class for handling null values more effectively, the `java.util.function` package for functional programming constructs, and the `java.util.stream` package for working with streams.

### Java 11

Java 11 introduced a few language enhancements, such as the var keyword for local variable type inference and the ability to launch a single-file source-code program directly with java command without explicitly compiling it.
Java 11 introduced several key changes and features to the Java programming language and the Java Development Kit (JDK). Some of the notable changes and features introduced in Java 11 include:

1. **Local-Variable Syntax for Lambda Parameters**: Java 11 allows you to use the `var` keyword for lambda parameters, enhancing code readability.

   ```java
   // Before Java 11
   (x, y) -> x + y

   // Java 11 and later
   (var x, var y) -> x + y
   ```

2. **HTTP Client**: Java 11 introduced a new, modern HTTP client API in the `java.net.http` package. It provides improved functionality for making HTTP requests and handling responses asynchronously.

   ```java
   import java.net.http.HttpClient;
   import java.net.http.HttpRequest;
   import java.net.http.HttpResponse;

   HttpClient client = HttpClient.newHttpClient();
   HttpRequest request = HttpRequest.newBuilder()
           .uri(URI.create("https://example.com"))
           .build();
   HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
   ```

3. **Flight Recorder**: Flight Recorder, previously a commercial feature, became available in Java 11 as part of the OpenJDK. It provides detailed insights into the runtime behavior of applications, aiding in monitoring and profiling.

4. **Epsilon Garbage Collector**: Java 11 introduced the Epsilon Garbage Collector, which is a no-op garbage collector. It's useful for performance testing and scenarios where garbage collection is not required.

5. **`var` in `Lambdas`**: Java 11 allowed the use of `var` in lambda expressions for lambda parameters.

6. **Unicode 10 Support**: Java 11 added support for Unicode 10, which includes a larger set of characters and emojis.

It's important to note that Java 11 is a Long-Term Support (LTS) release, which means it receives updates and security patches for an extended period of time, making it a stable choice for many production environments.

### What all features were introduced in java 17

Java 17, released in **September 2021**, is a **Long-Term Support (LTS)** version and introduced several new features, enhancements, and deprecations. Here's an **interview-ready summary** of key features added in Java 17:

---

### ✅ **1. Sealed Classes (Standard)**

When extending a sealed class in Java, you will get a 💥 compilation error if you violate its sealing rules — not a runtime error.

- **Purpose**: Restrict which classes can extend or implement a class or interface.
- **Example**:

  ```java
  public sealed class Shape permits Circle, Rectangle {}

  public final class Circle extends Shape {}
  public final class Rectangle extends Shape {}
  ```

- **Use Case**: Provides more control over class hierarchies — useful in domain modeling.

---

### ✅ **2. Pattern Matching for `switch` (Preview)**

- Adds pattern matching capabilities directly in `switch` statements.
- Improves readability and safety when switching over object types.
- **Example**:

  ```java
  switch (obj) {
      case String s -> System.out.println("A string: " + s);
      case Integer i -> System.out.println("An int: " + i);
      default -> System.out.println("Unknown");
  }
  ```
