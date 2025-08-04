# Abstraction vs. Encapsulation in Java

**Encapsulation** is about bundling data and the methods that operate on that data into a single unit (a class) and hiding the data from the outside world. 

**Abstraction** is about hiding the complex implementation details and showing only the essential features of an object.

Think of it this way:
* **Encapsulation** hides the **internal state** (the "how" it's built).
* **Abstraction** hides the **implementation complexity** (the "how" it works).


## 💊 Encapsulation: The Data Capsule

Encapsulation is one of the four fundamental OOP concepts. The core idea is to **wrap** data (variables) and code acting on the data (methods) together as a single unit. In encapsulation, the variables of a class are hidden from other classes and can be accessed only through the methods of their current class.

This is also known as **data hiding**.

#### How to Achieve Encapsulation

You achieve encapsulation in Java by:
1.  Declaring the variables of a class as `private`.
2.  Providing `public` **setter** and **getter** methods to modify and view the variables' values.

#### Example

    Consider a `Student` class. We don't want anyone to be able to set a student's age to a negative number. Encapsulation gives us control over this.

``` java
    public class Student {
        // private data members - hidden from the outside world
        private String name;
        private int age;

        // public getter method for name
        public String getName() {
            return name;
        }

        // public setter method for name
        public void setName(String name) {
            this.name = name;
        }

        // public getter method for age
        public int getAge() {
            return age;
        }

        // public setter method for age with validation
        public void setAge(int age) {
            if (age > 0) { // We control how the data is set
                this.age = age;
            } else {
                System.out.println("Age must be positive.");
            }
        }
    }

    // In another class
    public class School {
        public static void main(String[] args) {
            Student s1 = new Student();
            s1.setName("Rohan");
            s1.setAge(21); // The only way to set age

            // s1.age = -5; // This would cause a compile error because 'age' is private

            System.out.println("Name: " + s1.getName());
            System.out.println("Age: " + s1.getAge());
        }
    }

```

# Why is Encapsulation Important?

    Control: You control how data is accessed and modified. As seen above, we can add validation logic.

    Security: Hiding data protects it from unauthorized access and modification.

    Flexibility: The internal implementation can be changed without affecting the code that uses the class.


# 🎨 Abstraction: Hiding the Details

    Abstraction focuses on hiding the implementation complexity and showing only the functionality to the user. You expose the "what" an object does, not "how" it does it.

    A great real-world example is a TV remote. You press the power button to turn the TV on. You dont need to know the electronic circuitry that makes it happen; you only need to know the function of the button.

# How to Achieve Abstraction

    Abstraction is achieved in two ways in Java:

        - Abstract Classes (0 to 100% abstraction)
        - Interfaces (100% abstraction by default)

# Example

    Lets model different shapes. All shapes have an area, but the formula to calculate it is different for each. Abstraction is perfect for this.

    We create an abstract class Shape that has an abstract method calculateArea(). Any class that extends Shape must provide its own implementation for this method.

```java
    // Abstract class - cannot be instantiated
    abstract class Shape {
        // Abstract method - has no body, must be implemented by subclasses
        public abstract double calculateArea();

        // Concrete method
        public void display() {
            System.out.println("This is a shape.");
        }
    }

    class Circle extends Shape {
        private double radius;

        public Circle(double radius) {
            this.radius = radius;
        }

        // Providing the implementation for the abstract method
        @Override
        public double calculateArea() {
            return Math.PI * radius * radius;
        }
    }

    class Rectangle extends Shape {
        private double width;
        private double height;

        public Rectangle(double width, double height) {
            this.width = width;
            this.height = height;
        }

        // Providing the implementation for the abstract method
        @Override
        public double calculateArea() {
            return width * height;
        }
    }

    // In another class
    public class Drawing {
        public static void main(String[] args) {
            Shape myCircle = new Circle(5.0);
            Shape myRectangle = new Rectangle(4.0, 6.0);
            
            // We just call calculateArea(), we don't care HOW it's calculated
            System.out.println("Area of Circle: " + myCircle.calculateArea());
            System.out.println("Area of Rectangle: " + myRectangle.calculateArea());
        }
    }

```

# Why is Abstraction Important?

    Simplicity: Hides complex details from the user.

    Decoupling: Reduces the dependency between modules. You can change the inner workings of an object (e.g., improve the calculateArea algorithm) without changing the code that calls it.

    Focus: Helps the user focus on the high-level functionality.

# The Core Difference: Encapsulation vs. Abstraction

    - Encapsulation 

        - Data Hiding – To protect and control access to an objects internal state.
        - Achieved using private access modifiers and exposing data via public getter and setter methods.
        - Focuses on the internal working and state of an object.
        - It is a mechanism or a strategy to bundle data and behavior.
        - Like a medical capsule that hides the medicine (data) inside a shell to protect it from direct access.

    - Abstraction 

        - Complexity Hiding – To show only the essential features and hide the internal implementation.
        - Achieved using abstract classes and interfaces.
        - Focuses on the external view and behavior of an object.
        - It is a design principle used to handle complexity and increase readability.
        - Like a car dashboard that displays speed and fuel but hides engine details from the driver.


🚗 A Combined Real-World Analogy: A Car


    Abstraction: The driverr's view. You have a steering wheel, accelerator, and brake pedal. You know what they do (steer, go faster, stop), but you don't need to know how they work. The complex mechanics and electronics are hidden from you.

    Encapsulation: The engine itself. It's a self-contained unit. All its internal parts (pistons, crankshaft, etc.) are bundled together and sealed. You can't just reach in and move a piston. You interact with it through a controlled public interface (e.g., the accelerator pedal, which sends a signal to the engine).

❓ Common Interview Questions

    1. What is the primary difference between abstraction and encapsulation?

        Answer: Encapsulation is about data hiding (bundling data and methods), while abstraction is about detail hiding (hiding implementation complexity). Encapsulation hides the state; abstraction hides the behavior implementation.



    2. How do you achieve them in Java?
    
        Answer: Encapsulation is achieved with private members and public getters/setters. Abstraction is achieved with abstract classes and interfaces.

    3. Can you have abstraction without encapsulation? Or vice versa?

        Answer: Yes. An interface is an example of pure abstraction with no encapsulated data. A simple class with public fields and no methods would have data but no true encapsulation. However, they are most powerful when used together to create well-designed, secure, and maintainable objects.

# Give me a real-world example that illustrates both.

    Answer: Use the car analogy (dashboard vs. engine) or the TV remote analogy. Explain what part represents abstraction and what part represents encapsulation.


# Relation bw Abtraction and Encapsualation

    - Encapsulation and abstraction are closely related, complementary concepts in Java; encapsulation is a primary technique that helps achieve abstraction. They work together to create well-designed, maintainable, and secure objects.

    - In essence, abstraction is the design, and encapsulation is the implementation.

## How They Work Together

    - Think of abstraction as defining what an object should do, while encapsulation is about how it's done internally.

    - Abstraction focuses on the outside view of an object. It designs a simple, high-level interface and hides the unnecessary complexity. For example, when designing a Car class, abstraction decides that a driver needs simple methods like startEngine(), accelerate(), and brake().

    - Encapsulation is the mechanism that makes this simple interface possible. It bundles the data (like enginePistonStatus, fuelFlowRate, brakeFluidPressure) and the complex internal methods that act on that data. By making these details private, it hides them from the outside world, thereby enforcing the simple abstract view.

    - You cannot have a good abstraction without encapsulation. If all the car's internal data and methods were public, the user would be overwhelmed with complexity, and the simple abstraction of "pressing a pedal" would be lost.

## The Core Relationship

    The relationship can be summarized as: You use encapsulation to enforce the boundaries that abstraction designs.

    Design with Abstraction: You first think about the essential features. You create an interface or an abstract class (Shape) with an abstract method (calculateArea()). This is the abstract design.

    Implement with Encapsulation: A concrete class (Circle) then implements this design. It encapsulates its own specific data (private double radius) and the logic required to perform the calculation. By hiding the radius and other internal details, the Circle class ensures that users only interact with it through the abstract calculateArea() method.

    Encapsulation hides the implementation details, and abstraction leverages that hiding to present a simplified view to the user. They are two sides of the same coin, both aiming to create robust and easy-to-use code.


# Why do we have two different concepts, why can't be this a single concept ?

    While they are closely related, they can't be a single concept because they solve two different problems at two different levels of software design.

    Encapsulation is a mechanism focused on the object itself. Abstraction is a design principle focused on the interaction between objects.

## Different Problems, Different Focus

    The two concepts exist separately because they give developers precise language to talk about two distinct goals:

    Encapsulation's Goal: Protect Object Integrity 🛡️
    The main question encapsulation answers is: "How do I build a robust, self-contained object where the internal data can't be corrupted?" It achieves this by bundling data and methods together and hiding the internal state. It's all about building the component correctly and securely.

    Abstraction's Goal: Simplify System Usability 🎨
    The main question abstraction answers is: "How do I make this object easy to use for other parts of the system?" It achieves this by providing a simple, high-level interface and hiding the complex implementation details. It's all about designing a clean interface for others to use.

    You can have one without the other. A class could have all its data perfectly encapsulated (all private with getters/setters) but still have a very complex and non-abstract public interface. Conversely, an interface is pure abstraction but has no encapsulation because it has no implementation or data to hide.

## The Restaurant Analogy

    Think of a restaurant to see why the concepts are distinct:

    Encapsulation is the Kitchen: The kitchen is a restricted area. The chefs (methods) and ingredients (data) are bundled inside. As a customer, you can't just walk in and start using the ovens. This protects the integrity of the cooking process. This is encapsulation.

    Abstraction is the Menu: The menu provides you with a simple interface (getSteak(), getSalad()). You don't need to know the recipe, the cooking time, or the brand of the oven being used. The complex process is hidden from you. This is abstraction.

    Merging these two would be like saying the menu and the kitchen's internal safety rules are the same thing. They aren't. The menu is designed for the customer's ease of use (abstraction), while the kitchen rules are designed for the chef's operational integrity (encapsulation). You need both distinct concepts to run a successful restaurant.

# When we use interface and abstract class for abstraction, how exactly are we acheiving the abstraction ?

    You achieve abstraction with interfaces and abstract classes by separating an object's contract (the "what") from its implementation (the "how").

    By defining method signatures without providing the code, they force other developers to interact with a simplified view, hiding the complex details within the classes that implement them.

## How an Interface Achieves Abstraction

    An interface is a pure contract. It defines a set of method signatures that a class must implement.


    The Contract: The interface itself, like List, specifies what a list should be able to do (e.g., add(), get(), size()). This is the simple, abstract view.

    The Hidden Implementation: A class like ArrayList or LinkedList implements the List interface. Each provides its own complex, internal logic for how to add() or get() elements.

    Abstraction is achieved when your code interacts with the List type, not the specific ArrayList.

    Java

    // Programming to the interface (the abstraction)
    List<String> names = new ArrayList<>();

    // We only use the methods defined in the List contract.
    names.add("Ria"); 
    names.get(0);

    // We don't know or care HOW ArrayList stores the data or performs the 'add'.
    // The complexity is hidden.

## How an Abstract Class Achieves Abstraction
    An abstract class provides a partial contract. It achieves abstraction using its abstract methods, which, like interface methods, have no implementation.

    The Contract: The abstract methods (e.g., abstract double calculateArea();) define the required behaviors that subclasses must implement.

    The Hidden Implementation: A concrete subclass like Circle or Rectangle extends the abstract class and provides the specific, hidden formula for its calculateArea() method.

    The user of a Shape object simply calls shape.calculateArea() without needing to know the complex geometry behind it. The "how" is abstracted away inside the Circle or Rectangle class

# why we need the interface and the abstrct classes ?

    The reason we need interfaces and abstract classes is not to make methods available, but to enforce a standard contract and enable flexibility for the future.

    It's about moving from building a single object to designing an entire system.

    ## The Problem with Only Using Concrete Classes

    Imagine you're building an e-commerce application. You start by creating a payment class.

    ```Java

    // Your first class. It works perfectly fine on its own.
    public class CreditCardPayment {
        public void processCreditCard(double amount) {
            System.out.println("Processing credit card payment of $" + amount);
            // Complex logic for credit card processing...
        }
    }
    Now, in your checkout service, you write code that specifically uses this class.    

    public class CheckoutService {
        public void completePurchase(CreditCardPayment payment, double total) {
            // This method is tightly coupled to CreditCardPayment.
            payment.processCreditCard(total);
        }
    }
    ```

    This works great until your boss says, "Now we need to add PayPal payments."

    What do you do? You have to go back and change the CheckoutService class to also accept a PayPalPayment object. Your completePurchase method becomes messy with if-else statements. If you add more payment types (Apple Pay, Crypto), the problem gets worse. Your code is rigid and brittle.

## The Solution: A Common Contract

    Interfaces and abstract classes solve this by creating a blueprint or contract.

    Instead of starting with CreditCardPayment, you start by defining a contract for what it means to be a payment method.

    1. Create the Blueprint (The Interface)

    This is the abstraction. It says, "Any class that wants to be considered a payment method must have a processPayment method."

    
```Java
    // The contract. It doesn't know about credit cards or PayPal.
    public interface Payable {
        void processPayment(double amount); // This is the standard rule.
    }
```
    2. Create Different Implementations

    Now you can create multiple classes that follow this rule. Each class implements the "how" in its own unique way.

    Java

```Java
    public class CreditCardPayment implements Payable {
        @Override
        public void processPayment(double amount) {
            System.out.println("Processing credit card payment of $" + amount);
        }
    }

    public class PayPalPayment implements Payable {
        @Override
        public void processPayment(double amount) {
            System.out.println("Processing PayPal payment of $" + amount);
        }
    }
```

    3. Write Flexible Code

    Your CheckoutService no longer cares about the specific type of payment. It only cares that the object follows the Payable contract.

    Java
```Java
    public class CheckoutService {
        // This method works with ANY class that implements Payable.
        public void completePurchase(Payable paymentMethod, double total) {
            paymentMethod.processPayment(total);
        }
    }
```

    // In your main application:
```Java    
    CheckoutService checkout = new CheckoutService();
    Payable creditCard = new CreditCardPayment();
    Payable payPal = new PayPalPayment();

    checkout.completePurchase(creditCard, 100.0); // Works!
    checkout.completePurchase(payPal, 50.0);      // Also works!
```    

    Why This is Better:

    Enforces a Contract: It guarantees that all payment types have the exact same method signature, making them predictable and interchangeable.

    Enables Flexibility: The CheckoutService is now decoupled from the specific payment implementations. You can add a CryptoPayment class tomorrow, and you won't have to change a single line of code in CheckoutService. You just create the new class, implement Payable, and it works.

    That is why we need them. They let us design systems that are flexible, scalable, and easy to maintain, which is impossible if you only build specific, concrete classes.

# Encapsulation without Abstraction

    This happens when a class protects its data by making it private, but its public methods expose all the internal details. It's a self-contained unit, but it doesn't hide complexity or provide a simplified view.

    // This class is fully encapsulated but offers no abstraction.

```java    
    public class WeatherReading {

        // Encapsulation: Data is private.
        private double temperatureCelsius;
        private double humidityPercentage;

        public WeatherReading(double temperature, double humidity) {
            this.temperatureCelsius = temperature;
            this.humidityPercentage = humidity;
        }

        // Public getters and setters expose every internal detail.
        // There is no simplified view or hidden complexity.
        public double getTemperatureCelsius() {
            return temperatureCelsius;
        }

        public void setTemperatureCelsius(double temperatureCelsius) {
            this.temperatureCelsius = temperatureCelsius;
        }

        public double getHumidityPercentage() {
            return humidityPercentage;
        }

        public void setHumidityPercentage(double humidityPercentage) {
            this.humidityPercentage = humidityPercentage;
        }
    }
```

# Abstraction without Encapsulation

    This happens when you define a contract with an interface, but the implementing class exposes its internal state by making its fields public.

``` java

    // Abstraction: This interface defines a simple contract for saving data.
    interface Storable {
        void save();
    }

    // This class implements the contract but violates encapsulation.
    class GameSettings implements Storable {

        // Not encapsulated: Data is public and can be changed directly.
        public int difficultyLevel;
        public String playerName;

        public GameSettings(String name, int level) {
            this.playerName = name;
            this.difficultyLevel = level;
        }

        @Override
        public void save() {
            // Logic to save the public fields to a file...
            System.out.println("Saving settings for " + playerName + " at level " + difficultyLevel);
        }
    }

    // Client code using the abstraction
    public class Game {
        public static void main(String[] args) {
            // Programming to the interface (Abstraction)
            Storable settings = new GameSettings("Ryu", 5);
            settings.save(); // This works through the abstract contract.

            // However, encapsulation is broken...
            GameSettings concreteSettings = (GameSettings) settings;
            concreteSettings.difficultyLevel = 99; // Internal state changed directly!
            concreteSettings.save(); // Now saves the corrupted state.
        }
    }
```
    
    Why this works: The Storable interface provides a perfect abstraction. Code that depends on Storable only knows about the save() method. However, the GameSettings class is not encapsulated because its fields are public, allowing anyone to view and modify its state directly.



# Interview questions

    - What are the main benefits of using encapsulation in Java?

        - The main benefit of encapsulation is the ability to modify the implemented code without breaking the others code who have implemented the code.
        - It also provides us with maintainability, flexibility, and extensibility to our code.
        - The fields of a class can be made read-only or write-only.
        - A class can have total control over what is stored in its fields.
        - It prevents the other classes to access the private fields.

    - What is a Tightly encapsulated class in Java?

        Ans: If each variable is declared as private in the class, it is called tightly encapsulated class in Java. For tightly encapsulated class, we are not required to check whether class contains getter and setter method or not and whether these methods are declared as public or not.

    
    # Getter and Setter methods are also called accessor and mutator method

# Reflection in java

    Reflection in Java is a feature that allows a program to examine and modify its own structure and behavior at runtime

    In simple terms, reflection lets Java code look at itself while it's running. It can see its own classes, methods, and variables and even use them, all without knowing their names when the code was written.

    Think of it like having a blueprint of a house while you are standing inside it. You can see all the rooms (classes), doors (methods), and furniture (variables) listed on the blueprint and decide to open a door you've never seen before.

## Why Frameworks Like Spring Use It

    Frameworks like Spring use reflection to automate tasks that would otherwise require a massive amount of manual configuration. The main reason is to achieve Inversion of Control (IoC) and Dependency Injection (DI).

    Here’s what Spring does with it:

    Component Scanning: When your Spring application starts, it doesn't know about your classes like UserService or ProductController. It uses reflection to scan your project's code for classes marked with special annotations like @Component, @Service, or @Controller.

    Creating Objects (Beans): Once Spring finds these classes, it uses reflection to create objects (called "Beans") from them, even though it didn't know their names beforehand.

    Dependency Injection: This is the most important part. If your ProductController needs a ProductService, you simply declare it with @Autowired:

```    Java

    @Controller
    public class ProductController {
        @Autowired // Hey Spring, I need a ProductService object here!
        private ProductService productService;
    }
    
```    
    Spring uses reflection to:

    See the private ProductService productService; field.

    Find the ProductService bean it created earlier.

    "Inject" or assign that object to the private field, even though it's private.

    Without reflection, you would have to manually create and connect all these objects yourself, which would be extremely tedious and error-prone in a large application. Reflection allows Spring to do all this wiring automatically based on your annotations.