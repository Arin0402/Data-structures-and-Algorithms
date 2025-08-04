### What all collections have you used

List
Set
Map

the above three are the interfaces and have implementations as follows
ArrayList, LinkedList
Hashset, LinkedHashSet, TreeSet
HashMap, LinkedHashMap, TreeMap

### Difference b/w list and set

List allow duplicate values, set does not
List values are accessed using index, set values are accessed using hash

### Difference b/w linked list and arraylist

- arraylist uses a dynamic array to store elements while linkedlist internally uses a doubly linked list to store the elements
- manipulation with arraylist is slow because it internally uses an array. If any element is removed from the array all the bits are shifted in memory. While it is faster with linkedlist because it uses a doubly linked list so no shifting is required in memory
- arraylist is better for storing and accessing data, while linkedlist is better for manipulating data.

### When to use linkedlist vs when to use arraylist in java

Great question! In Java, both `ArrayList` and `LinkedList` implement the `List` interface, but they have different underlying data structures — which makes them suitable for different use cases.

---

### 🔍 Summary of Differences

| Feature                                   | `ArrayList`              | `LinkedList`                      |
| ----------------------------------------- | ------------------------ | --------------------------------- |
| Underlying Data Structure                 | Dynamic array            | Doubly linked list                |
| Access by Index                           | ✅ Fast (O(1))           | ❌ Slow (O(n))                    |
| Insertion at End                          | ✅ Fast (amortized O(1)) | ✅ Fast (O(1))                    |
| Insertion/Deletion at Beginning or Middle | ❌ Slow (O(n))           | ✅ Fast (O(1)) if node is known   |
| Memory Usage                              | Efficient                | More memory (extra node pointers) |
| Iteration                                 | ✅ Fast (cache-friendly) | ❌ Slower (poor locality)         |
| Random Access                             | ✅                       | ❌                                |

---

### ✅ When to Use `ArrayList`

Use `ArrayList` when:

- You **frequently access elements by index** (e.g., `list.get(i)`).
- You **add/remove elements only at the end**.
- **Memory efficiency** matters.
- You need **fast iteration**.

#### Example:

```java
List<String> cities = new ArrayList<>();
cities.add("Delhi");
cities.add("Mumbai");
System.out.println(cities.get(1)); // Fast access
```

---

### ✅ When to Use `LinkedList`

Use `LinkedList` when:

- You **frequently add/remove elements from the start/middle**.
- You’re implementing **queues or stacks**.
- You don’t need random access.

#### Example:

```java
List<String> tasks = new LinkedList<>();
tasks.addFirst("Task A");
tasks.addFirst("Task B"); // O(1)
System.out.println(tasks.removeLast()); // O(1)
```

---

### 👎 When Not to Use

- Avoid `LinkedList` if you need **random access**.
- Avoid `ArrayList` if you do **lots of insertions/removals** in the middle or start.

---

### 🔄 Real-life Use Cases

| Use Case                      | Prefer       |
| ----------------------------- | ------------ |
| Lookups by index              | `ArrayList`  |
| Large datasets, fewer changes | `ArrayList`  |
| Queue (FIFO)                  | `LinkedList` |
| Stack (LIFO)                  | `LinkedList` |
| Frequent insertions/deletions | `LinkedList` |

---

Let me know if you'd like performance benchmarks or internal diagram comparisons!

### which is better

Arraylist list = new ArrayList<String>(); //tightly coupled
List<String> list = new ArrayList<String>(); //loosely coupled, using list interface here, in future if we want we could use LinkedList instead of ArrayList

### How can i create a custom arraylist where i don't want to allow duplicate

```java
    public class CustomArrayList extends ArrayList{
            @Override
            public boolean add(Object o){
                if(this.containse(o)) return true;
                else return super.add(o);
            }
    }

    public class Main{
        public static void main(String[] args){
            ArrayList<String> arr = new CustomArrayList();
            arr.add(1);
            arr.add(1);
            arr.add(1);
            arr.add(2);
            System.out.println(arr);
        }
    }
```

### What is the difference b/w fail fast and fail safe operator

- A iterator which will fail when we do any modification(adding or deleting) while iterating a collection is called fail fast iterator ex - Arraylist, Hashmap, vector
- Iterator who allow us to modify in middle while iterating a collection is called non-fail fast iterator ex - CopyOnWriteArrayList, CopyOnWriteArraySet, ConcurrentHashmap

### What is the need of concurrentHashMap & how it is different from the HashMap

Concurrent hashmap is failsafe while hashmap is not
Concurrent hashmap is thread safe i.e synchronized
Concurrent hashmap does not allow null keys and values
Suppose a multithreaded env in which one thread is iterating over the map and other is trying to add some items in it, then it won;t be allowed with hashmap because hashmap is fail fast and will throw exception.

### Why use concurrenthashmap when we have hashtable

because concurrenthashmap is fail safe. While synchronizing hastable locks the whole data structure while concurrent hashmap do it on segment basis.

### Can i access linked list elements by index in java

Yes, you **can access elements by index** in a `LinkedList` in Java using the `.get(index)` method — because `LinkedList` implements the `List` interface.

### 🔍 But: It's **not efficient**.

Unlike `ArrayList`, which gives **O(1)** access time, accessing an element by index in a `LinkedList` takes **O(n)** time, because:

- It **starts from the beginning** (or end, if index is closer to the end),
- And **traverses node by node** to the target index.

---

### ✅ Example:

```java
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> names = new LinkedList<>();
        names.add("Alice");
        names.add("Bob");
        names.add("Charlie");

        System.out.println(names.get(1));  // Output: Bob
    }
}
```

---

### 🚨 Caution:

Using `.get(index)` repeatedly in a loop on a `LinkedList` is **inefficient**:

```java
for (int i = 0; i < list.size(); i++) {
    list.get(i);  // O(n) for each call ⇒ total O(n²)
}
```

Instead, use an **iterator**:

```java
for (String item : list) {
    System.out.println(item);
}
```

---

### Summary:

| Feature       | `ArrayList` | `LinkedList` |
| ------------- | ----------- | ------------ |
| `.get(index)` | O(1)        | O(n)         |

So yes, you **can** access by index in `LinkedList`, but **avoid it if performance matters**.

### What is the difference between collections and streams in java ?

The difference between **Collections** and **Streams** in Java boils down to **what** they represent and **how** they are used.

---

### 🔸 1. **What they represent**

| Feature          | **Collections**                             | **Streams**                             |
| ---------------- | ------------------------------------------- | --------------------------------------- |
| **Nature**       | A data **structure** (e.g., List, Set, Map) | A data **flow/pipeline** for processing |
| **Stores data?** | Yes – stores elements in memory             | No – processes data on the fly (lazy)   |
| **Reusable?**    | Yes – you can iterate multiple times        | No – can be consumed only once          |

---

### 🔸 2. **Purpose**

| Aspect               | **Collections**                           | **Streams**                                       |
| -------------------- | ----------------------------------------- | ------------------------------------------------- |
| **Designed for**     | Storing, accessing, and manipulating data | Processing data declaratively (map, filter, etc.) |
| **Processing style** | External iteration (`for`, `for-each`)    | Internal iteration (`stream().filter()...`)       |

---

### 🔸 3. **Examples**

#### ✅ **Collection Example (ArrayList)**

```java
List<String> names = new ArrayList<>();
names.add("Alice");
names.add("Bob");

for (String name : names) {
    System.out.println(name);
}
```

#### ✅ **Stream Example**

```java
List<String> names = Arrays.asList("Alice", "Bob", "Charlie");

names.stream()
     .filter(name -> name.startsWith("A"))
     .map(String::toUpperCase)
     .forEach(System.out::println);  // Output: ALICE
```

---

### 🔸 4. **Key Differences Summary**

| Feature               | **Collections**           | **Streams**                   |
| --------------------- | ------------------------- | ----------------------------- |
| Stores data?          | Yes                       | No                            |
| Data processed        | Eager                     | Lazy (on-demand)              |
| Can be reused         | Yes                       | No (one-time use)             |
| Supports modification | Yes (`add()`, `remove()`) | No (usually read-only)        |
| Iteration type        | External                  | Internal                      |
| Ideal use             | Data storage              | Data transformation/filtering |

---

### 🔸 Use Together

You often **use both together**:

```java
List<String> filtered = names.stream()
    .filter(name -> name.length() > 3)
    .collect(Collectors.toList());  // Back to collection
```

---

Let me know if you want real-world scenarios where you’d use one over the other.

CONCISE
In Java, Collections and Streams serve different purposes.

Collections are in-memory data structures like List, Set, and Map that are primarily used to store and manage data. They support operations such as adding, removing, and accessing elements. Iteration over collections is typically done using external iteration — for example, using loops.

On the other hand, Streams were introduced in Java 8 and are used for processing data in a declarative and functional style. Streams don't store data — they represent a pipeline of operations that can transform or filter data from a source (like a collection or an array). Streams use internal iteration, which leads to cleaner and more concise code.

One key difference is that streams are consumed once — after performing a terminal operation like collect() or forEach(), the stream cannot be reused. Collections, however, are reusable and modifiable.

For example, if I have a List<String>, I can use a stream to filter names starting with "A" and convert them to uppercase in a single, readable pipeline:

### what error does the code throw when stream is used again

A runtime excpetion illegalstate exception is thrown
When you try to **reuse a Java Stream after a terminal operation**, it throws a **`java.lang.IllegalStateException`** with the message:

> **"stream has already been operated upon or closed"**

### ✅ **Example:**

```java
import java.util.*;
import java.util.stream.*;

public class StreamReuseExample {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Alice", "Bob", "Charlie");

        Stream<String> stream = names.stream();

        // First terminal operation – this is valid
        stream.forEach(System.out::println);

        // Reusing the same stream – this will throw IllegalStateException
        stream.filter(name -> name.startsWith("A"))
              .forEach(System.out::println);
    }
}
```

### ❌ **Output:**

```text
Alice
Bob
Charlie
Exception in thread "main" java.lang.IllegalStateException: stream has already been operated upon or closed
```

---

### ✅ **Correct Approach:**

You should **create a new stream** each time you want to operate on it:

```java
names.stream().filter(...).forEach(...);  // OK
names.stream().map(...).collect(...);     // OK
```

Let me know if you want this explained with a diagram or interview phrasing.
