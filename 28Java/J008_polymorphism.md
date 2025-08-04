### Polymorphism in java ?

Polymorphism in Java refers to the ability of an object to take on different forms or have multiple types. It allows a single interface or base class to be used to represent various concrete implementations or derived classes.

There are two types of polymorphism commonly seen in Java:

Compile-time Polymorphism (Static Polymorphism):

Method Overloading: In Java, you can define multiple methods with the same name but different parameter lists within a class. The appropriate method is selected at compile-time based on the number, type, and order of the arguments passed.
Constructor Overloading: Similar to method overloading, constructors can also be overloaded within a class.
Runtime Polymorphism (Dynamic Polymorphism):

Method Overriding: In Java, a subclass can provide its own implementation of a method defined in its superclass. This is achieved by using the @Override annotation and providing the same method signature in the subclass. At runtime, the appropriate method implementation is determined based on the actual object type rather than the reference type.
Inheritance: Polymorphism is closely related to inheritance. Objects of a derived class can be treated as objects of their superclass, allowing them to be used interchangeably. This allows for code reuse and enables the principle of substitutability.
Polymorphism is an essential concept in object-oriented programming (OOP) as it facilitates code flexibility, extensibility, and modularity. It allows different classes to adhere to a common interface or base class, enabling code to work with objects in a generic and flexible manner. Polymorphism promotes loose coupling and allows for code that is more maintainable and adaptable to changes.

## Difference b/w static and dynamic polymorphism in java

Polymorphism is one of the fundamental concepts in object-oriented programming that allows objects of different classes to be treated as objects of a common superclass. In Java, polymorphism can be categorized into two main types: static polymorphism (compile-time polymorphism) and dynamic polymorphism (runtime polymorphism). Here's the difference between the two:

**1. Static Polymorphism (Compile-Time Polymorphism):**

- **Method Overloading:** Static polymorphism is achieved through method overloading. Method overloading allows you to define multiple methods in a class with the same name but with different parameter lists (different types or different numbers of parameters).
- **Decision at Compile Time:** The determination of which method to invoke is made by the Java compiler at compile-time based on the method signature (the name and the parameter list). It is also known as early binding or compile-time binding.

- **Example:** Here's an example of method overloading, which demonstrates static polymorphism:

  ```java
  class Calculator {
      int add(int a, int b) {
          return a + b;
      }

      double add(double a, double b) {
          return a + b;
      }
  }
  ```

  In this example, the `add` method is overloaded with different parameter types, and the compiler resolves the appropriate method to call based on the arguments.

- **Pros:** Static polymorphism results in faster method invocation since the decision is made at compile-time, and there's no need for runtime method lookup.

**2. Dynamic Polymorphism (Runtime Polymorphism):**

- **Method Overriding:** Dynamic polymorphism is achieved through method overriding. Method overriding allows a subclass to provide a specific implementation of a method that is already defined in its superclass.

- **Decision at Runtime:** The determination of which method to invoke is made at runtime, based on the actual type of the object. It is also known as late binding or runtime binding.

- **Example:** Here's an example of method overriding, which demonstrates dynamic polymorphism:

  ```java
  class Animal {
      void makeSound() {
          System.out.println("Animal makes a sound");
      }
  }

  class Dog extends Animal {
      @Override
      void makeSound() {
          System.out.println("Dog barks");
      }
  }

  Animal a = new Dog();
  a.makeSound();
  ```

  In this example, the `makeSound` method is overridden in the `Dog` class, and the specific implementation in the `Dog` class is invoked at runtime.

- **Pros:** Dynamic polymorphism allows for flexibility and extensibility in your code. It enables the implementation of the same method in different ways in different subclasses.

In summary, the main difference between static and dynamic polymorphism in Java is when the decision of which method to call is made. Static polymorphism is determined at compile-time based on the method signature, whereas dynamic polymorphism is determined at runtime based on the actual object type. Static polymorphism is achieved through method overloading, while dynamic polymorphism is achieved through method overriding.

### Example

A mobile phone can work as a camera, calculator and mp3 player thereby taking different forms.

### Runtime polymorphism is also called the dynamic method dispatch.
