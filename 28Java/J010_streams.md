Stream API introduced in java 8 and it is used to process collections of objects with functional style of coding using lambda expressions.

Java Streams is a powerful feature introduced in Java 8 for processing sequences of elements (e.g., collections like lists, sets, or arrays) in a functional and declarative way. Streams provide a concise and expressive way to perform operations on data, such as filtering, mapping, and reducing, making your code more readable and maintainable.

Here are some key concepts and operations associated with Java Streams:

1. **Stream Creation**:

   - Streams can be created from various data sources like collections, arrays, I/O channels, or even by generating elements on the fly.

   ```java
   List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
   Stream<Integer> stream = numbers.stream();
   ```

2. **Intermediate Operations**:

   - Intermediate operations transform a stream into another stream. They are lazy, which means they don't process elements until a terminal operation is invoked.

   ```java
   Stream<Integer> evenNumbers = numbers.stream()
       .filter(n -> n % 2 == 0)  // Filter elements
       .map(n -> n * 2);         // Map elements to double their values
   ```

3. **Terminal Operations**:

   - Terminal operations trigger the processing of elements and produce an ultimate/final result.

   ```java
   long count = evenNumbers.count();  // Count the number of elements
   int sum = numbers.stream()
       .reduce(0, (acc, n) -> acc + n);  // Reduce to find the sum
   ```

4. **Collectors**:

   - Collectors are special terminal operations that allow you to accumulate elements into a collection, map, or other data structure.

   ```java
   List<Integer> evenNumberList = evenNumbers.collect(Collectors.toList());
   Map<Integer, String> numberToSquareMap = numbers.stream()
       .collect(Collectors.toMap(n -> n, n -> Integer.toString(n * n)));
   ```

5. **Parallel Streams**:

   - Streams can be processed in parallel to leverage multi-core processors. You can convert a stream to a parallel stream using the `parallel()` method.

   ```java
   long count = numbers.parallelStream().count(); // Process in parallel
   ```

6. **Stream API vs. Collection API**:

   - Streams are not a replacement for collections. While collections are used to store and manage data, streams are used for processing data. You can convert a stream back to a collection if needed.

   ```java
   List<Integer> evenNumberList = evenNumbers.collect(Collectors.toList());
   ```

7. **Common Operations**:

   - Streams support various common operations like `filter`, `map`, `reduce`, `forEach`, `distinct`, `sorted`, `limit`, and `skip`, among others.

   ```java
   List<String> names = people.stream()
       .filter(p -> p.getAge() > 18)
       .map(Person::getName)
       .sorted()
       .collect(Collectors.toList());
   ```

Java Streams provide a more functional and concise way to work with data compared to traditional loops, and they promote immutability and parallelism, which can lead to more efficient and maintainable code.

### Reduce stream in java

The `reduce` operation in Java Streams is used to combine the elements of a stream into a single result by applying a binary operator. It repeatedly applies the operator to the elements of the stream, accumulating a result. Here's a proper example of using `reduce` to find the sum of integers in a list:

```java
import java.util.Arrays;
import java.util.List;

public class ReduceExample {

    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);

        // Using reduce to find the sum of integers in the list
        int sum = numbers.stream()
                .reduce(0, (accumulator, element) -> accumulator + element);

        System.out.println("Sum of numbers: " + sum);
    }
}
```

In this example:

1. We have a list of integers called `numbers`.
2. We use the `stream()` method to create a stream from this list.
3. The `reduce` operation is applied to the stream. It takes two arguments:
   - The initial value (`0` in this case), which serves as the starting value for the accumulator.
   - A lambda expression that defines how to accumulate elements. In this lambda, `accumulator` represents the accumulated result, and `element` represents each element in the stream. Here, we simply add the current element to the accumulator.
4. The result of the `reduce` operation is the sum of all elements in the list, which is printed to the console.

When you run this code, it will output:

```
Sum of numbers: 15
```

This demonstrates how the `reduce` operation can be used to perform aggregations on elements in a stream, in this case, finding the sum of integers in the list.

### Another example

Here's an example of using the `reduce` operation with a custom object in Java:

Suppose you have a custom class called `Product` representing products with a name and a price, and you want to find the total price of a list of products:

```java
import java.util.Arrays;
import java.util.List;

class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public double getPrice() {
        return price;
    }
}

public class ReduceCustomObjectExample {

    public static void main(String[] args) {
        List<Product> products = Arrays.asList(
            new Product("Laptop", 1000.0),
            new Product("Phone", 500.0),
            new Product("Tablet", 300.0)
        );

        // Using reduce to find the total price of products
        double totalPrice = products.stream()
                .mapToDouble(Product::getPrice)  // Extract the price of each product
                .reduce(0.0, (accumulator, element) -> accumulator + element);

        System.out.println("Total Price of Products: $" + totalPrice);
    }
}
```

In this example:

1. We have a custom class `Product` with a constructor to create products with a name and a price, and a `getPrice` method to get the price of a product.

2. We create a list of `Product` objects representing different products.

3. We use the `stream()` method to create a stream from the list of products.

4. The `mapToDouble` operation is used to extract the price of each product, converting the stream of products into a stream of `double` values.

5. Finally, the `reduce` operation is applied to the stream of `double` values. It starts with an initial value of `0.0` and accumulates the prices by adding each element to the accumulator.

6. The result is the total price of all products, which is printed to the console.

When you run this code, it will output:

```
Total Price of Products: $1800.0
```

This demonstrates how you can use the `reduce` operation with a custom object to perform aggregations on elements in a stream, in this case, finding the total price of the products.

### What is stream in java 8?

A stream is a sequence of objects that supports various methods which can be pipelined to produce the desired result.
The features of java stream are -

1. A stram is not a data structure instead it takes input from the collectiosn, arrays or IO channels
2. Streams don't change the original data structure, they only provide the result as per the pipelined methods.

### if streams doesn't modify the data structure then what about foreach? You can modify contents using it

Excellent question! Let's clear up the confusion:

---

### ✅ Yes, you're right:

> "Streams don't change the original data structure, they only provide the result as per the pipelined methods."

This is **true** for operations like `.map()`, `.filter()`, `.collect()`, etc.

They are **non-mutating** and **return new data** (or results).

---

### 🤔 Then what is `.forEach()`?

`.forEach()` is a **terminal operation** in the Stream API that is used to **perform side effects** (like printing or modifying external variables), but it **does not alter the source collection**.

```java
List<String> names = List.of("Alice", "Bob", "Charlie");

names.stream()
     .forEach(name -> System.out.println(name)); // prints names but doesn't change 'names'
```

---

### 🔥 But can you use `.forEach()` to **mutate objects**?

Yes! If you're iterating over **mutable objects**, you can modify **the objects inside**, but **not the structure** (like adding/removing elements from the list).

```java
List<User> users = new ArrayList<>();
users.add(new User("Alice"));
users.add(new User("Bob"));

users.stream()
     .forEach(user -> user.setActive(true)); // ✅ this modifies the *objects*, not the list

System.out.println(users); // All users are now active
```

---

### ❌ What it **won’t** do:

- You can't add/remove items to the collection inside `.forEach()` safely.
- It doesn’t modify the collection itself (like changing the list size or structure).

---

### TL;DR:

> `.forEach()` is a **terminal operation** that **doesn’t change the structure** of the source. But you **can mutate the contents** (if they’re mutable), which is different from operations like `.map()` that return a new stream without side effects.

Want to dive into `forEachOrdered`, or see a comparison with `for` loops?
