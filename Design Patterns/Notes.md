# What is design pattern ?

    - Design patterns are typical solutions to commonly occurring problems in software design. They are like pre-made blueprints that you can customize to solve a recurring design problem in your code.

    - The code of the same pattern applied to two different programs may be different.

    - It teaches you how to solve all sorts of problems using principles of object-oriented design.

# Idioms

    - The most basic and low-level patterns are often called idioms. They usually apply only to a single programming language.

# Architectural patterns

    - The most universal and high-level patterns are architectural patterns. Developers can implement these patterns in virtually any language. Unlike other patterns, they can be used to design the architecture of an entire application.


# Types od design patterns

    - Creational patterns provide object creation mechanisms that increase flexibility and reuse of existing code.

    - Structural patterns explain how to assemble objects and classes into larger structures, while keeping these structures flexible and efficient.

    - Behavioral patterns take care of effective communication and the assignment of responsibilities between objects.


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

    - Liskov substitution principle
        
        - Derived classes should be usable in place of their parent class without unexpected behavior. This helps avoid unpredictable consequences of changes.

        - https://www.youtube.com/watch?v=129QkkXUHeQ

    - Interface segregation principle

        - No class should be forced to implement interfaces or methods that it will not use. It's better to have specific interfaces, rather than a single general interface.

        - https://youtu.be/XI7zep97c-Y?t=773

    - Dependency inversion principle

        - Classes should depend on interfaces rather than concrete classes

        - https://youtu.be/XI7zep97c-Y?t=923


