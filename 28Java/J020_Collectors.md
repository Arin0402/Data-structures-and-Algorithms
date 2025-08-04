### What kind of parameter does collect expect in java ?

In Java, the `collect` method expects a `Collector` as a parameter. The `Collector` interface is part of the `java.util.stream` package and is used to specify how elements of a stream should be collected into a container, such as a `List`, `Set`, or `Map`, or to perform other custom reduction operations.

The `Collector` interface defines a set of methods for collecting elements:

```java
<R, A> R collect(Collector<? super T, A, R> collector)
```

Here's a breakdown of the generic parameters used in the `collect` method:

- `T`: The type of elements in the stream.
- `A`: The type of the intermediate accumulation result, which is used to accumulate elements as they are processed.
- `R`: The type of the final result, which is the result of the collection operation.
- `Collector<? super T, A, R>`: A `Collector` instance that specifies how elements should be collected and transformed.

When you use `.collect(Collectors.toList())`, you are using a predefined `Collector` provided by the `Collectors` class to collect the stream elements into a `List`. In this case, `T` represents the type of elements in the stream, `A` represents the intermediate result (usually not explicitly used when collecting to a `List`), and `R` represents the final result, which is the `List` of collected elements.

Here's an example of how to use `.collect(Collectors.toList())`:

```java
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CollectToListExample {
    public static void main(String[] args) {
        // Create a stream of integers
        Stream<Integer> numbersStream = Stream.of(1, 2, 3, 4, 5);

        // Collect the stream elements into a List
        List<Integer> numbersList = numbersStream.collect(Collectors.toList());

        // Print the collected list
        System.out.println("Collected List: " + numbersList);
    }
}
```

In this example, the `collect(Collectors.toList())` operation collects the elements of the stream into a `List` of integers.

### is Collector a functional interface ?

No, the `Collector` interface in Java is not a functional interface. A functional interface is an interface that has exactly one abstract (non-default) method and can be used with lambda expressions and method references. The `Collector` interface in Java has multiple abstract methods, making it a non-functional interface.

Because of its multiple abstract methods, the `Collector` interface cannot be considered a functional interface and cannot be used directly with lambda expressions. However, you can use predefined collectors from the `Collectors` class or create custom collectors by implementing the `Collector` interface when working with streams. Predefined collectors are often used in practice and make it easy to perform common collection operations, such as grouping, mapping, and reducing elements in a stream.

### How to sort in java

Using comparable or comparator

```java
package Sorting;

import java.util.*;
import java.util.stream.Collectors;

class Student implements Comparable<Student>{
    protected String firstName;
    protected String secondName;
    protected Integer age;

    public Student(String firstName, String secondName, Integer age) {
        this.firstName = firstName;
        this.secondName = secondName;
        this.age = age;
    }

    public static void printStudent(){
        System.out.println("I am a static function, cannot call non static ones.");
    }

    public void getMyMarksheet(){
        printStudent(); // i can call static methods.
    }


    @Override
    public String toString() {
        return "Student{" +
                "firstName='" + firstName + '\'' +
                ", secondName='" + secondName + '\'' +
                ", age=" + age +
                '}';
    }


    @Override
    public int compareTo(Student s) {
        return firstName.compareTo(s.firstName);
    }
}


class CustomComparator implements Comparator<Student>{

    @Override
    public int compare(Student o1, Student o2) {
        return o1.firstName.compareTo(o2.firstName);
    }
}


public class Main {
    public static void main(String[] args) {

        List<Student> studentList = new ArrayList<>();
        studentList.add(new Student("Akshit", "Goyal", 25));
        studentList.add(new Student("Pawan", "Goyal", 55));
        studentList.add(new Student("Sunita", "Goyal", 55));
        studentList.add(new Student("Arin", "Goyal", 22));

        Collections.sort(studentList); //gives compilation error unless comparable was implemented
        Collections.sort(studentList, new CustomComparator());

        studentList.stream().forEach((student -> System.out.println(student.toString())));

        List<Integer> numbers = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9);
        Integer oddSquareSum = numbers.stream()
                .filter(n -> n % 2 != 0) // Keep only odd numbers
                .map(n -> {
                    return n * n; // Square each odd number
                })
                .reduce(0, (accumulator, currentValue) -> {
                    return accumulator + currentValue; // Add each squared number
                });
        System.out.println(oddSquareSum);
    }
}

```

### Does `Collections.sort(...)` return a new list or modify the original?

**Answer:**
✅ It **modifies the original list** in-place.
❌ It **does NOT** return a new list.

---

### 🔹 Examples:

#### 1. **Using Comparable**:

```java
Collections.sort(studentList);  // Sorts in-place using compareTo()
```

#### 2. **Using Comparator**:

```java
Collections.sort(studentList, new CustomComparator()); // Sorts in-place using compare()
```

Both **mutate** the original `studentList`.

---

### 🔹 Why No Return?

The method signature is:

```java
public static <T extends Comparable<? super T>> void sort(List<T> list)
```

Return type: `void`

So it doesn’t produce a new list — just reorders elements of the one you pass in.

---

### ✅ If You Want a New Sorted List:

Use Java Streams instead:

```java
List<Student> sortedList = studentList.stream()
    .sorted(new CustomComparator())
    .collect(Collectors.toList());
```

✅ This **does not modify** the original list and gives you a **new sorted list**.

---

### Summary for Interviews:

> "`Collections.sort()` modifies the given list in-place and doesn't return a new list. If a new sorted list is needed, use `Stream.sorted()`."

Let me know if you want examples with custom `Comparable` or `Comparator`.
