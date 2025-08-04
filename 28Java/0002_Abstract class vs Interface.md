# What is the difference bw interface and abstract class

    The main difference is that an abstract class is for creating a base for closely related classes that share common code (an "is-a" relationship), while an interface is for defining a capability that unrelated classes can implement (a "can-do" relationship). A class can only extend one abstract class but can implement multiple interfaces.


# Abstract Class 🧬

    To share common code and state among related subclasses. Models an "is-a" relationship (e.g., Dog is an Animal).

        - A class can extend only one abstract class.
        - Can have both abstract methods (no body) and concrete methods (with a body) and static method.
        - Can have instance variables (static, non-static, final, non-final). Can store state for an object.
        - Can have a constructor, which is called by subclasses using super().
        - A subclass uses the extends keyword.
        - 
            non-static variables (each object gets its own copy)
            static variables (shared across all instances)
            final variables (constants)
            Any combination of access modifiers (private, protected, etc.)

# Interface 📜

    To define a contract of capabilities that can be implemented by any class. Models a "can-do" relationship (e.g., a Car and a Bird can both be Flyable).

        - A class can implement multiple interfaces.
        - Traditionally only had abstract methods. Since Java 8, can also have default and static methods with bodies.
        - Variables are implicitly public static final (constants). Cannot store instance-specific state.
        - Cannot have a constructor.
        - An implementing class uses the implements keyword.