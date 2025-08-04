### Why java streams are made to be consumed only once ?

Great question! Java **streams** are **designed to be consumed only once** because of their **lazy and pipeline-based nature**. Here's a breakdown of **why**:

---

### 🔄 1. **Streams represent a pipeline of operations**

- A stream isn’t a data structure; it’s a **conveyor belt** of data flowing through operations (like `filter`, `map`, `reduce`).
- Once this "belt" reaches the end (`terminal operation` like `collect()` or `forEach()`), it’s done.
- After that, the pipeline is **closed**, and trying to reuse it would violate the idea of a linear data flow.

---

### ⚙️ 3. **Efficiency & Resource Safety**

- Many stream sources (e.g. files, sockets) are **one-time-use**.
- If streams were reusable by default, they’d have to **cache all data**, which could:
  - Increase memory usage
  - Break performance optimizations
  - Conflict with infinite or very large streams

---

### 🚫 What happens if you try to reuse?

```java
Stream<String> stream = Stream.of("a", "b", "c");
stream.forEach(System.out::println);
stream.forEach(System.out::println); // Throws IllegalStateException
```

The second call fails with:

```
java.lang.IllegalStateException: stream has already been operated upon or closed
```

---

### ✅ What to do if you need it again?

- Just create a **new stream**:

```java
List<String> data = Arrays.asList("a", "b", "c");
data.stream().forEach(System.out::println); // First time
data.stream().forEach(System.out::println); // Again, from scratch
```

---

### TL;DR:

Java streams are single-use to enforce a clean, efficient, and safe data-processing model—where each stream is a _once-through_ pipeline of transformations and results. Think of it like a file read stream—you consume it, and it’s done.

Let me know if you want a deep dive into how internal iterators or spliterators manage this behind the scenes!

### What is a functional interface ?

An interface with a single method is called a functional interface. It has only one abstract method but can have any number of default and static methods.
And an interface with no method is called a marker interface.
Most of the popular streams in java like filter, map, reduce accepts a functional interface as an argument, see intellij for more details.

### Functional interface that were already there before java 8?

Runnable, Callable, equals

### Can we extend functional interface over another functional interface ?

in this case the subinterface would have to remove the @FunctionalInterface annotation as it will throw compilation errors for the obvious reasons.

### Can we create an object of an interface ?

We can not create the object of interface but we can create the implementation of the interface and hence the object.

### What kind of parameters does different streams consume ?

1.  Map - accepts a functional interface Function<T, R> where T is the input and R is the response. It has apply() method which is actually called while mapping

        Function<String, Integer> stringLengthFunction = new Function<String, Integer>() {
            @Override
            public Integer apply(String str) {
                return str.length();
            }
        };

2.  Filter - accepts a functional interface Predicate<T> where T is the input and it evaluates to either true or false. It has test() method which is actually called while filtering

### Predicate in java

In Java, a `Predicate` is a functional interface that represents a boolean-valued function. It can be used to define a condition or a test that determines whether a given input meets a certain criteria and returns either `true` or `false`. Predicates are commonly used in various contexts, such as filtering elements in collections, validating data, or making decisions based on conditions.

The `Predicate` interface is part of the `java.util.function` package introduced in Java 8 as part of the Java Functional Interfaces feature. It defines a single abstract method:

```java
boolean test(T t);
```

Here, `T` is the type of the input to the predicate, and the `test` method takes an argument of type `T` and returns a boolean value.

Here's a simple example of how you can use a `Predicate` to filter elements in a list:

```java
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class PredicateExample {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        numbers.add(10);
        numbers.add(5);
        numbers.add(20);
        numbers.add(3);
        numbers.add(8);

        // Define a Predicate to filter even numbers
        Predicate<Integer> isEven = num -> num % 2 == 0;

        // Use the Predicate to filter the list
        List<Integer> evenNumbers = filterList(numbers, isEven);

        System.out.println("Even numbers: " + evenNumbers);
    }

    // Method to filter a list using a Predicate
    public static <T> List<T> filterList(List<T> list, Predicate<T> predicate) {
        List<T> result = new ArrayList<>();
        for (T item : list) {
            if (predicate.test(item)) {
                result.add(item);
            }
        }
        return result;
    }
}
```

In this example, we define a `Predicate` named `isEven` to test if a number is even. We then use the `filterList` method to filter a list of numbers using the `isEven` predicate, resulting in a list of even numbers.

Predicates provide a convenient way to encapsulate conditions and make code more readable and expressive, especially when working with functional programming concepts and collections.

### Functional interface introduced in java 8?

Function - used by map, R apply(T t)
Predicate - used by filter, bool test(T t)
Consumer - has void accept(T t) method. It only consumes the input but won't return anything. foreach uses this method
Supplier - used for late initialization, T get()

### Disadvantage of lambda expression

1. Hard to use without IDE
2. Hard to debug

### Difference between **`Arrays.asList()`** and **`List.of()`** in Java:

## ✅ 1. `Arrays.asList()`

### 🔹 What it does:

- Converts an **array** or varargs to a **fixed-size list backed by the array**.

### 🧪 Example:

```java
List<String> list = Arrays.asList("a", "b", "c");
```

### ⚠️ Key Characteristics:

- **Modifiable elements**: You can change values with `set()`.
- **Not resizable**: Can't `add()` or `remove()` elements — throws `UnsupportedOperationException`.
- Backed by the original array — changes reflect both ways.

### ❌ Example:

```java
list.add("d"); // Throws UnsupportedOperationException
list.set(0, "x"); // ✅ Works
```

---

## ✅ 2. `List.of()` (Java 9+)

### 🔹 What it does:

- Creates an **immutable list** from provided elements.

### 🧪 Example:

```java
List<String> list = List.of("a", "b", "c");
```

### ⚠️ Key Characteristics:

- **Truly immutable**: You **cannot modify, add, or remove** elements.
- Not backed by an array — safer and cleaner.
- Throws `NullPointerException` if any element is `null`.

### ❌ Example:

```java
list.set(0, "x"); // Throws UnsupportedOperationException
list.add("d");    // Throws UnsupportedOperationException
List.of("a", null, "b"); // Throws NullPointerException
```

---

## 🧠 Summary Table:

| Feature                  | `Arrays.asList()`              | `List.of()` (Java 9+)           |
| ------------------------ | ------------------------------ | ------------------------------- |
| Mutability               | Partially modifiable (`set()`) | Immutable (no `set/add/remove`) |
| Resize allowed           | ❌ No                          | ❌ No                           |
| Allows `null` values     | ✅ Yes                         | ❌ No                           |
| Backed by original array | ✅ Yes                         | ❌ No                           |
| Java version required    | Java 5+                        | Java 9+                         |

---

### ✅ Which should you use?

| Use Case                                | Recommended       |
| --------------------------------------- | ----------------- |
| You need a **fixed-size, mutable list** | `Arrays.asList()` |
| You need an **immutable list**          | `List.of()`       |

---

Let me know if you want a visual or performance comparison too!
