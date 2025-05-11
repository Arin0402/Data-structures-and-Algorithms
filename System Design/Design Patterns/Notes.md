# What is design pattern ?

    - Design patterns are typical solutions to commonly occurring problems in software design. They are like pre-made blueprints that you can customize to solve a recurring design problem in your code.

    - The code of the same pattern applied to two different programs may be different.

    - It teaches you how to solve all sorts of problems using principles of object-oriented design.

# Idioms

    - The most basic and low-level patterns are often called idioms. They usually apply only to a single programming language.

# Architectural patterns

    - The most universal and high-level patterns are architectural patterns. Developers can implement these patterns in virtually any language. Unlike other patterns, they can be used to design the architecture of an entire application.


# Types od design patterns

    - Creational Design Patterns – “How to create objects?”        
        - Deal with object creation mechanisms, trying to create objects in a manner that is suitable to the situation.
        - Think of this like ways to build a house.

            Example: You want to build a house.

            You can build it yourself (manual creation).
            You can hire a contractor (Factory).
            You can buy a ready-made house (Prototype).
            You can use a blueprint and builder (Builder pattern).
            You can make sure only one house exists (Singleton).

    - Structural Design Patterns – “How to connect objects?”
        - Deal with object composition, i.e., how classes and objects are composed to form larger structures.
        - Think of this like ways to build structures with LEGO blocks.

            Example: You have LEGO pieces (classes/objects).

            You can wrap one inside another to add more features (Decorator).
            You can convert one block to fit another (Adapter).
            You can hide the complexity by using a remote control instead of many buttons (Facade).        

    -  Behavioral Design Patterns – “How do objects talk to each other?”
        - Focus on communication between objects, what goes on between objects.

            Example: In a classroom:

            Students raise their hand to speak (Observer).
            A teacher gives instructions to students (Command).
            Each student solves the same problem in their own way (Strategy).
            If one student changes the slide, others update their notes (Observer).        

# Abstract class and interface

    - Use abstract classes when objects are closely related and share common functionality (e.g., Animal class for Dog and Cat).
    
    - Use interfaces when you want to define a contract for unrelated objects (e.g., Flyable for Bird and Airplane).


      Feature	        Abstract Class	                            Interface
    
    - Methods	        Can have both implemented and abstract	    All methods are abstract (or default)
    - Fields (State)	Can have fields	                            Cannot have fields
    - Inheritance	    Single inheritance	                        Multiple inheritance
    - Use Case	        Common base class with shared code	        Contract for behavior
    - Access 
      Modifiers	        Can use any access modifier	                Methods are public by default

# SOLID principles

    - airtcle for reference = https://www.digitalocean.com/community/conceptual-articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design

    - SOLID is an acronym for the first five object-oriented design (OOD) principles by Robert C. Martin (also known as Uncle Bob).

    - These principles establish practices for developing software with considerations for maintaining and extending it as the project grows. 

    - SOLID stands for:

        S - Single-responsibility Principle
        O - Open-closed Principle
        L - Liskov Substitution Principle
        I - Interface Segregation Principle
        D - Dependency Inversion Principle

    - Single responsibility principle

        - A class should have one and only one reason to change, meaning that a class should have only one job.

        - For example, consider an application that takes a collection of shapes—circles and squares—and calculates the sum of the area of all the shapes in the collection.
        
        - Consider a scenario where the output should be converted to another format like JSON.

        - The AreaCalculator class would handle all of the logic, violating the single responsibility principle. 
        
        - The AreaCalculator class should only be concerned with the sum of the areas of provided shapes. It should not care whether the user wants JSON or HTML.

        - To address this, you can create a separate SumCalculatorOutputter class and use that new class to handle the logic you need to output the data to the user.

    - Open-closed principle

        - Software entities like classes, modules, and functions should be open for extension but closed for modification. 

        - This means that a class should be extendable without modifying the class itself.

        - Consider a scenario where the user would like the sum of additional shapes like triangles, pentagons, hexagons, etc. You would have to constantly edit this file and add more if/else blocks. That would violate the open-closed principle.

        - A way you can make this sum method better is to remove the logic to calculate the area of each shape out of the AreaCalculator class method and attach it to each shape’s class.

        - So we can create seperate classes for square and circle

        - Now, you can create another shape class and pass it in when calculating the sum without breaking the code.

        - However, another problem arises. How do you know that the object passed into the AreaCalculator is actually a shape or if the shape has a method named area?

        - Coding to an interface is an integral part of SOLID.

        - Create a ShapeInterface that supports area:

            interface ShapeInterface
            {
                public function area();
            }

        - ex:   

            interface Shape {
                double area();
            }

            class Rectangle implements Shape {
                double length, width;
                public double area() {
                    return length * width;
                }
            }

            class Circle implements Shape {
                double radius;
                public double area() {
                    return Math.PI * radius * radius;
                }
            }

            class AreaCalculator {
                public double calculate(Shape shape) {
                    return shape.area();
                }
            }


    - Liskov substitution principle
        
        - Derived classes should be usable in place of their parent class without unexpected behavior. This helps avoid unpredictable consequences of changes.

        - https://www.youtube.com/watch?v=129QkkXUHeQ

    - Interface segregation principle

        - No class should be forced to implement interfaces or methods that it will not use. It's better to have specific interfaces, rather than a single general interface.

        - https://www.youtube.com/watch?v=Kv7Twu66LuM

    - Dependency inversion principle

        - High-level modules should not depend on low-level modules. Both should depend on abstractions.
          Abstractions should not depend on details. Details should depend on abstractions.

        - In simple words
            - "Don’t make your main code rely on specific things. Make it rely on general rules or interfaces, so you can swap the parts easily."

        - https://www.youtube.com/watch?v=aGym5w0qomk


