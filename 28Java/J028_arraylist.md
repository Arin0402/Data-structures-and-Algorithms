### Arrays are static then how can arraylist dynamically resize itself.

Arrays in Java have a fixed size, meaning once you create an array with a specific size, you cannot change that size. For example, if you create an array of integers like this:

```java
int[] myArray = new int[5];
```

`myArray` can only hold 5 integers, and you cannot add or remove elements from it without creating a new array with a different size.

On the other hand, `ArrayList` in Java is a dynamic data structure that is implemented using arrays internally. `ArrayList` can dynamically resize itself to accommodate more elements. When an `ArrayList` is created, it starts with an initial capacity. If you add more elements than the current capacity allows, the `ArrayList` automatically increases its capacity by creating a new, larger array and copying the existing elements to the new array. This process is known as resizing or rehashing.

Here's how it works:

1. **Initial Capacity:**

   - When you create an `ArrayList`, you can specify an initial capacity, for example:

   ```java
   ArrayList<Integer> list = new ArrayList<>(10);
   ```

2. **Adding Elements:**

   - As you add elements to the `ArrayList` using the `add()` method, the `ArrayList` keeps track of its size. If the size exceeds the current capacity, the `ArrayList` internally creates a new array with a larger size (usually, it doubles the current capacity) and copies the elements from the old array to the new array.

   ```java
   list.add(1);
   list.add(2);
   // ... adding more elements
   ```

3. **Automatic Resizing:**
   - When the internal array is resized, the old array is discarded, and the elements are copied to the new, larger array.
   - This process happens transparently to the programmer, allowing you to work with `ArrayList` as if it were a dynamically resizing array.

In summary, while arrays in Java have a fixed size, `ArrayList` provides a dynamic and convenient way to work with a resizable array. The resizing complexity is hidden from the programmer, allowing you to focus on your application logic without worrying about managing the array size manually.
