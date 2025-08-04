### Shallaow vs deep copy

// ## Shallow Copy:

// A shallow copy creates a new object but references the same memory locations as the original object. In other words, it copies the object references without duplicating the referenced objects themselves.
// Changes made to the original object will be reflected in the copied object and vice versa, as they point to the same underlying data.
// Shallow copy is a relatively simple and efficient process since it does not involve duplicating the entire object graph.
// By default, Java's clone() method performs a shallow copy.
//
// ## Deep Copy:
//
// A deep copy creates a new object and recursively duplicates all the referenced objects within the object graph.
// The copied object and the original object will have separate memory locations and independent sets of data.
// Changes made to the original object will not affect the copied object, as they are entirely separate entities.
// Deep copy is a more complex and potentially resource-intensive process, especially when dealing with complex object structures or large amounts of data.
// Java's default clone() method does not perform a deep copy. Instead, it performs a shallow copy that needs to be overridden to achieve deep copying.
// In summary, a shallow copy creates a new object but maintains references to the same underlying data, while a deep copy creates a completely independent copy by recursively duplicating the entire object graph. The choice between deep and shallow copy depends on the requirements of the specific use case and the desired behavior when modifying the copied object or its referenced objects.

#### A shallow copy copies an object and references to the same inner objects, while a deep copy creates a completely independent object with copies of all nested objects

### What is the best way to create deep copy in java

In Java, creating a **deep copy** of an object means creating a new object along with **new copies of all referenced objects**, recursively — not just copying the references.

Here are the **best approaches**, depending on your context:

---

### ✅ 1. **Manual Copy (Recommended for Full Control)**

The safest and most flexible way is to write a custom `deepCopy()` method:

```java
class Person {
    String name;
    Address address;

    Person(String name, Address address) {
        this.name = name;
        this.address = new Address(address); // Use copy constructor
    }

    // Deep copy method
    public Person deepCopy() {
        return new Person(this.name, new Address(this.address));
    }
}

class Address {
    String city;

    Address(String city) {
        this.city = city;
    }

    // Copy constructor
    Address(Address other) {
        this.city = other.city;
    }
}
```

✅ Best for: Precision, performance, and avoiding third-party libs.

---

### ✅ 2. **Using Serialization (Generic but Slower)**

If your class implements `Serializable`:

```java
public static <T extends Serializable> T deepCopy(T object) {
    try {
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream out = new ObjectOutputStream(bos);
        out.writeObject(object);

        ByteArrayInputStream bis = new ByteArrayInputStream(bos.toByteArray());
        ObjectInputStream in = new ObjectInputStream(bis);
        return (T) in.readObject();
    } catch (IOException | ClassNotFoundException e) {
        throw new RuntimeException("Deep copy failed", e);
    }
}
```

⚠️ All referenced classes must implement `Serializable`.

✅ Best for: Quick generic copy for small, simple object graphs.

---

### ✅ 3. **Using a Copy Constructor or Cloneable Interface**

- `Cloneable` only performs **shallow copy** by default.
- Override `clone()` and perform deep copy manually:

```java
class Person implements Cloneable {
    String name;
    Address address;

    public Person(String name, Address address) {
        this.name = name;
        this.address = address;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Person cloned = (Person) super.clone();
        cloned.address = (Address) address.clone(); // Deep clone
        return cloned;
    }
}
```

⚠️ `Cloneable` is often avoided due to its fragile design.

✅ Best for: Legacy codebases or frameworks relying on `clone()`.

---

### ✅ 4. **Using Libraries (e.g., Apache Commons, Gson, Jackson)**

#### ➤ Apache Commons Lang

```java
Person cloned = SerializationUtils.clone(original);
```

(Requires implementing `Serializable`.)

#### ➤ Gson (JSON-based)

```java
Gson gson = new Gson();
String json = gson.toJson(original);
Person copy = gson.fromJson(json, Person.class);
```

⚠️ Won't preserve custom types like transient fields or circular references.

✅ Best for: Prototyping or data objects.

---

### 🟩 Final Recommendation

- Use **manual deep copy** (copy constructor or custom method) for **full control** and **performance**.
- Use **serialization/Gson** for **quick-and-dirty copies** of simple objects.
- Avoid relying on `Cloneable` unless required.

Let me know the class structure you’re dealing with, and I can help you write an ideal `deepCopy()` method for it.
