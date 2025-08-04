## SOLID principles

//https://www.youtube.com/watch?v=XI7zep97c-Y

1. S - Single responsibility principle - a class should have only single reason to change.
2. O - open/ closed principle - open for extension but closed for modification.
3. L - liskov substituion principle - if class B is subtype of class A, then we should be able to replace object of A with B without breaking the behaviour of the program. Subclass should extend the capabilty of parent class not narrow it down.
4. I - Interface Segregation Principle - interfaces should be such that client should not implement unnecessary functions they do not need.
5. D - Dependency inversion principle - class should depend on interfaces rather than concrete classes.

### Explain all SOLID Principles with example

Certainly! Let's go through each of the SOLID principles with examples:

**1. Single Responsibility Principle (SRP):**

- SRP states that a class should have only one reason to change. It should have a single responsibility.

**Example:**

```java
class Order {
    public void calculateTotalPrice() {
        // Calculate the total price of the order
    }

    public void saveOrderToDatabase() {
        // Save the order to the database
    }
}
```

In this example, the `Order` class has two responsibilities: calculating the total price and saving the order to the database. It violates SRP because if either of these responsibilities changes, the class needs to be modified.

**Refactored Example:**

```java
class Order {
    public void calculateTotalPrice() {
        // Calculate the total price of the order
    }
}

class OrderRepository {
    public void saveOrderToDatabase(Order order) {
        // Save the order to the database
    }
}
```

By separating the responsibilities into two classes, we adhere to SRP. If one aspect changes (e.g., database handling), it doesn't affect the other.

**2. Open/Closed Principle (OCP):**

- OCP states that software entities should be open for extension but closed for modification.

**Example:**

```java
class Shape {
    public void draw() {
        // Draw the shape
    }
}
```

If we want to add new shapes without modifying the `Shape` class, we can use inheritance:

```java
class Circle extends Shape {
    public void draw() {
        // Draw a circle
    }
}

class Rectangle extends Shape {
    public void draw() {
        // Draw a rectangle
    }
}
```

Now, we can add new shapes (e.g., `Triangle`) without modifying the existing `Shape` class.

**3. Liskov Substitution Principle (LSP):**

-In other words: If class B is a subclass of class A, then we should be able to replace A with B without breaking the behavior of the program.
eg - List can be replaced with ArrayList<> LinkedList<> because they are very similar
**Example:**

```java
class Bird {
    public void fly() {
        // Fly like a generic bird
    }
}

class Sparrow extends Bird {
    public void fly() {
        // Fly like a sparrow
    }
}
```

A `Sparrow` can be used in place of a `Bird`, and it behaves as expected. This adheres to LSP.

**4. Interface Segregation Principle (ISP):**

- ISP states that clients should not be forced to depend on interfaces they do not use.

**Example:**

```java
// Violation of ISP
interface Worker {
    void work();
    void eat();
}
```

If a class only needs the `work` method, it's forced to implement `eat`. Instead, we can split the interface:

```java
interface Workable {
    void work();
}

interface Eatable {
    void eat();
}
```

Now, classes can implement the relevant interfaces.

**5. Dependency Inversion Principle (DIP):**

- DIP states that high-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.

**Example:**

```java
class LightBulb {
    public void turnOn() {
        // Turn on the light bulb
    }

    public void turnOff() {
        // Turn off the light bulb
    }
}
```

A high-level class depending on a low-level class:

```java
class Switch {
    private LightBulb bulb;

    public Switch(LightBulb bulb) {
        this.bulb = bulb;
    }

    public void operate() {
        if (/* some condition */) {
            bulb.turnOn();
        } else {
            bulb.turnOff();
        }
    }
}
```

Instead, we can introduce an abstraction:

```java
interface Switchable {
    void turnOn();
    void turnOff();
}

class LightBulb implements Switchable {
    public void turnOn() {
        // Turn on the light bulb
    }

    public void turnOff() {
        // Turn off the light bulb
    }
}

class Switch {
    private Switchable device;

    public Switch(Switchable device) {
        this.device = device;
    }

    public void operate() {
        if (/* some condition */) {
            device.turnOn();
        } else {
            device.turnOff();
        }
    }
}
```

Now, `Switch` depends on the abstraction `Switchable`, adhering to DIP.

#### What is th prototype pattern in java

The Prototype pattern is a creational design pattern that enables the creation of new objects by cloning an existing object, known as the prototype. This approach is beneficial when creating objects is resource-intensive or complex. Instead of instantiating a class from scratch, the Prototype pattern allows for the creation of a copy of an existing object.

```java
// Prototype interface
interface Shape {
    Shape clone();
    void draw();
}

// Concrete prototype class
class Circle implements Shape {
    private int radius;

    public Circle(int radius) {
        this.radius = radius;
    }

    public Circle clone() {
        return new Circle(this.radius);
    }

    public void draw() {
        System.out.println("Drawing circle with radius: " + radius);
    }
}

// Client class
public class PrototypeExample {
    public static void main(String[] args) {
        Circle circlePrototype = new Circle(5);

        Shape newCircle = circlePrototype.clone();
        newCircle.draw(); // Output: Drawing circle with radius: 5
    }
}
```
