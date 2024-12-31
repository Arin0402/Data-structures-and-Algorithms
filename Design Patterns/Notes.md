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