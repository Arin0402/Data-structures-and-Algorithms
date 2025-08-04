### ✅ What is a `HashMap`?

> A `HashMap` stores data in **key-value pairs**, and allows **fast lookup, insertion, and deletion** using **hashing**.

---

### 🔍 Internal Working:

#### 1. **Hashing the Key**

- When you put a key-value pair:

  ```java
  map.put("apple", 100);
  ```

- Java calls `key.hashCode()` to generate a **hash code**.
- The hash code is used to calculate an **index** in an internal **array of buckets**.

---

#### 2. **Handling Collisions**

- Two keys can have the **same index** (called a **collision**).
- HashMap handles collisions using:

  - **Linked Lists** (Java 7 and earlier)
  - **Balanced Trees (Red-Black Tree)** if the chain gets too long (Java 8+)

---

#### 3. **Inserting**

- If the bucket is empty, the entry is placed directly.
- If not, it checks:

  - If the key already exists → update value.
  - If it's a new key → add to the chain/tree.

---

#### 4. **Retrieving**

- For `map.get("apple")`:

  - Hash code is calculated.
  - Index is found.
  - It traverses the chain/tree in that bucket to find the matching key using `.equals()`.

---

### 📦 Internal Structure:

```text
HashMap uses:
- An array of Nodes (buckets)
- Each Node stores: key, value, hash, and next (link to next node)
```

---

### 🧠 Example Flow:

```java
HashMap<String, Integer> map = new HashMap<>();
map.put("apple", 100);
map.put("banana", 200);
map.get("apple"); // Returns 100
```

---

### ⚙️ Resize (Rehashing):

- If the number of elements exceeds the load factor (default 0.75), the array is **resized (doubled)** and all keys are **rehashed** to new positions.

---

### ✅ Summary:

| Step      | What Happens                             |
| --------- | ---------------------------------------- |
| `put()`   | Calculates hash → finds index → inserts  |
| `get()`   | Calculates hash → finds index → searches |
| Collision | Handled by chaining or red-black trees   |
| Resize    | When capacity > threshold (load factor)  |

---

Let me know if you'd like a diagram or code to visualize the process better!

### By default what is taken as the size of array of linked lists in hashmaps ?

By default, when you create a `HashMap` in Java without specifying an initial capacity, it is initialized with a default capacity of 16 buckets. This means that the underlying array that stores key-value pairs initially has 16 slots (buckets) available.

Here's an example of creating a `HashMap` without specifying an initial capacity:

```java
HashMap<String, Integer> hashMap = new HashMap<>();
```

In this example, the `HashMap` is created with the default initial capacity of 16 buckets. However, the `HashMap` will automatically resize itself (rehash) and double its capacity when the number of elements (key-value pairs) exceeds a certain threshold, typically when it reaches 75% of the current capacity. This resizing operation ensures that the `HashMap` remains efficient in terms of time complexity for storing and retrieving elements even as more elements are added.

You can also specify a different initial capacity when creating a `HashMap` if you have a specific capacity requirement or want to optimize for memory usage or performance. For example:

```java
HashMap<String, Integer> hashMap = new HashMap<>(32); // Specifies an initial capacity of 32.
```

Keep in mind that the choice of the initial capacity should be based on your specific use case and expected number of elements to be stored in the `HashMap`. Choosing an appropriate initial capacity can help reduce the frequency of resizing operations and improve performance when dealing with a large number of elements.

### Difference b/w open addressing and separate chaining

Open addressing and separate chaining are two common techniques used to handle collisions in hash tables, including data structures like `HashMap`. These techniques are employed when two different keys produce the same hash code, resulting in a collision.

### ✅ **1. Separate Chaining**

> Collisions are handled using a **linked list** (or tree) at each bucket index.

#### 🔧 How it works:

- Each bucket holds a **list** of entries.
- If multiple keys hash to the same index, they're stored **in the same bucket**.

#### 🧪 Example:

```
Index 3 → [Key1 → Value1] → [Key2 → Value2]
```

#### ✅ Pros:

- Simple to implement.
- Performance remains good even when load factor > 1.

#### ❌ Cons:

- Uses **extra memory** for linked lists.
- May be slower due to pointer traversal.

---

### ✅ **2. Open Addressing**

> All elements are stored **in the hash table array itself**.
> On collision, the algorithm **searches for the next free slot**.

#### 🔧 Techniques used:

- **Linear probing**: check next slot (+1)
- **Quadratic probing**: check i² steps away
- **Double hashing**: use a second hash function

#### 🧪 Example (Linear Probing):

```
Index 3 → taken
Check 4 → free → insert here
```

#### ✅ Pros:

- No extra memory for lists.
- Good cache performance (array-based).

#### ❌ Cons:

- More sensitive to **load factor**.
- Can cause **clustering** and performance drop.

---

### 🧠 Summary Table:

| Feature              | **Separate Chaining**                 | **Open Addressing**                       |
| -------------------- | ------------------------------------- | ----------------------------------------- |
| Storage              | Linked list/tree at each index        | All entries in array itself               |
| Memory Usage         | More (extra list nodes)               | Less (no external structures)             |
| Load Factor Handling | Can go beyond 1                       | Must stay below 1                         |
| Lookup Time (avg)    | O(1 + α) where α = load factor        | O(1) if load is low, worse when clustered |
| Example Use          | Java `HashMap` (uses chaining + tree) | Some custom hash tables, Python's dict    |

**Choosing Between Open Addressing and Separate Chaining:**
The choice between open addressing and separate chaining depends on factors like the expected number of collisions, memory constraints, and the desired trade-off between memory efficiency and access speed. Both techniques are commonly used in practice and have their advantages and disadvantages, making them suitable for different use cases.

### explain open addressing to a rookie

Certainly! Let's explain open addressing, a collision resolution technique used in hash tables, in simple terms for someone new to the concept:

Imagine you have a big collection of boxes, and you want to store items in these boxes so you can find them quickly when you need them. To make it easy to find each item, you decide to use a magic formula that tells you exactly which box to put each item in.

Now, you start putting items in boxes. You follow the magic formula for each item, and it tells you which box to use. So far, so good. But what happens when you have two items that the magic formula says should go into the same box? This is called a "collision."

Here's where open addressing comes in:

Instead of just giving up and putting both items in the same box, you decide to use a clever trick. When a collision occurs, you don't give up; instead, you look at the next box (like checking the next door) and see if it's empty. If it's empty, you put the item in that box. If it's not empty, you keep moving to the next box until you find an empty one.

When you need to find an item later, you use the same magic formula to know which box it should be in. You go to that box and check if the item is there. If it's not, you know it's not in that box, so you keep checking the next boxes until you find it.

That's the basic idea of open addressing: when there's a collision, you don't give up; you keep looking for the next available box to put the item in. It's like finding a parking spot in a crowded parking lot—you don't stop at the first occupied spot; you keep driving until you find an empty one.

### is open addressing slow ?

Yes, open addressing can potentially increase both search (lookup) and insert (put) times compared to other collision resolution techniques like separate chaining. The performance of open addressing depends on factors such as the load factor (the ratio of the number of stored elements to the number of available slots), the quality of the probing sequence, and the specific implementation details.

Here are some considerations:

**1. Search Time:**

- In open addressing, searching for an element may require probing through the table to find the correct slot where the element is stored. If the load factor is low and the table is not densely populated, this may not significantly impact search times.

- However, as the load factor increases and the table becomes more densely populated, searching can become slower because you may need to probe through more slots before finding the desired element.

**2. Insertion Time:**

- The insertion time in open addressing can also be affected by the load factor. When the table is not densely populated (low load factor), insertions can be fast because empty slots are readily available, and you don't need to probe through many slots.

- As the load factor increases and the table becomes more crowded, finding an empty slot for insertion can become slower because you may need to probe through multiple slots.

In summary, open addressing can have increased search and insertion times when compared to simpler collision resolution techniques like separate chaining, especially as the load factor increases. However, it can still be a viable choice for certain scenarios, and its performance can be managed and optimized through careful design, probing sequence selection, load factor monitoring, and rehashing strategies.

### Removing a key from hashmap

```java
   Map<String, Integer> myMap = new HashMap<>();

        // Add some key-value pairs
        myMap.put("Apple", 1);
        myMap.put("Banana", 2);
        myMap.put("Cherry", 3);

        System.out.println("Map before removal: " + myMap);

        // Remove a key and its associated value
        String keyToRemove = "Banana";
        Integer removedValue = myMap.remove(keyToRemove);
```
