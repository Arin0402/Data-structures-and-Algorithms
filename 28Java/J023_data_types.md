## Data types are primarily of two kinds:

Primitive data types: Variables hold the value of data item. char in Java uses Unicode characters

Non-Primitive/Reference data types: Variables hold the reference of the memory location where the data item is stored.

### what is public static void main(String[] args) ?

`public static void main(String[] args)` is the **entry point** of any standard Java application — it's the method the **JVM (Java Virtual Machine)** looks for to start your program. Let’s break it down:

---

### 🔍 **Breakdown of each keyword:**

#### ✅ `public`

- **Access modifier**: Makes the `main` method accessible from **outside the class**, specifically by the **JVM**.
- If it weren't `public`, the JVM wouldn't be able to call it, and you'd get an error like:
  ```
  Error: Main method not found in class
  ```

---

#### ✅ `static`

- Means you **don’t need to create an object** of the class to run `main`.
- The JVM calls `main` **directly using the class name**, like:
  ```java
  MyClass.main(args);
  ```

---

#### ✅ `void`

- The method **doesn’t return anything**.
- It’s meant to **run your code**, not give back a value.

---

#### ✅ `main`

- The **method name**. Java looks **specifically** for `main` as the program’s **starting point**.
- It's a convention, and the JVM is hardcoded to look for it.

---

#### ✅ `String[] args`

- A **parameter** that lets you pass **command-line arguments** when running the program.
- Example:
  ```bash
  java HelloWorld Hello GPT
  ```
  In your code:
  ```java
  System.out.println(args[0]); // prints "Hello"
  System.out.println(args[1]); // prints "GPT"
  ```

---

### 🔁 Putting it all together:

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, world!");
    }
}
```

- The **JVM** finds this `main` method
- It executes it **without creating an object**
- It can accept parameters from the command line
- And it doesn’t return anything when done

---

Let me know if you want to see how to pass arguments or how it compares to other languages like Python or C++.

### guess the output

    String name = "Oliver";
    name.concat(" Carter");
    System.out.println(name);  //Output Oliver

## -- java compare to function

    	String temp = "Thomas"
    	temp.compareTo("Robert"); //output - 2
    	temp.compareTo("Tywin"); //outpur - -12

    		if s1 and s2 are two strings which are to be compared
    		if s1 == s2 then output is 0
    		if s1 > s2 then output is 1
    		if s1 < s2 then output is -1

## difference b/w equals and ==

    -- equals method compares the content of the object
    == compares the reference of objects

## Static keyword

Static keyword is used to make a member belong to a class, and not to any of its individual objects. Only one copy of the member is maintained across all the instances. We can have static variables, methods, and blocks.

    a) STATIC BLOCK
    -- Java supports a special block, called static block which gets executed when the class is loaded in the JVM. A static block is used for initializing static variables.

    	The code in the static block will get executed, once either of the below condition satisfies, when
    		--The object is created
    		--The first time a static member of that class is accessed.

If a class has static members which require complex initialization, in that case, the static block is the solution.

private static int counter;
static {
int randomNumber = 30;
counter = (int) Math.pow(randomNumber, 3);
}

    	Rules of Static Block
    		Static block cannot return a value.
    		Static blocks get executed before constructors.
    		Static block is used to initialize static variables only; it gives compilation error if we try to initialize non-static variables.
    		Keywords like this and super cannot be used inside the static block.


    b)
    	Now have a look at this,

    	class Ford {
    	    private String modelNo;
    	    private String color;
    	    private String bookingId;
    	    private static int noOfCars;
    	    public static void generateBookingId() {
    	        this.bookingId = "F" + noOfCars;    // Compilation Error! Why?
    	   }
    	}
    	The static method doesn't belong to any object, so it does not know a member of which object we are trying to access. Trying to do so will result in a compilation error.

    	A static context, i.e. static blocks and static methods, cannot access non-static (instance) members directly.

    	However, non-static methods can access static members.

### Variable arguments

    	void displayContactDetails(int customerId, long ...contactNumbers){
    	    System.out.println("Customer Id: "+customerId);
    		System.out.println("Contact Numbers: ");

    		for (long contactNumber : conatactNumbers)
    		    System.out.println(contactNumber);
    	}

## Predict the output of the code given below.

    class Tester{
    	public void  testerMethod(float a, float b) {
            System.out.println((a+b));
        }

        public void testerMethod(float a, int b) {
            System.out.println((a+b));
        }

        public static void main(String[] args) {
            Tester test = new Tester();
            test.testerMethod(7, 3);
        }
    }

    Option 10.0 is Correct

    Explanation :

    It calls a more specific method. i.e method with same datatypes in parameters. For eg. (float, int) is near to our input (7,3) as compared to (float, float)

### Rmove an object from a list in java

```java
import java.util.ArrayList;
import java.util.List;

public class RemoveElement {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Orange");
        list.add("Grape");

        int indexToRemove = 1;

        if (indexToRemove >= 0 && indexToRemove < list.size()) {
            list.remove(indexToRemove); //using index
            list.remove("Apple"); //using object
            System.out.println("List after removing element at index " + indexToRemove + ": " + list);
        } else {
            System.out.println("Invalid index. Please provide an index within the range of the list.");
        }
    }
}
```

### what is the difference between byte and int in java ?

The byte and int are primitive data types in Java used to store whole numbers, but they differ in size and range. A byte is an 8-bit signed integer, meaning it can store values from -128 to 127. An int is a 32-bit signed integer, capable of storing values from -2,147,483,648 to 2,147,483,647.
