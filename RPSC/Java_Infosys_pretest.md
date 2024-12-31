A variable name can consist of 
A-Z, a-z, 0-9, _ , $

The first character must not be a digit.
Blank spaces cannot be used in variable names.
Java keywords cannot be used as variable names.
Variable names are case-sensitive.
There is no limit on the length of a variable name but by convention, it should be between 4 to 15 chars.
Variable names always should exist on the left-hand side of assignment operators.

- primitive - hold single value (Total 8)
        - Numeric
            - Integer
                - int (4byte)
                - short (2)
                - long(8)
                - byte(1) (-127 to 128)
            - Floating
                - float(4)
                - double(8)
        - Non-numeric
            - char(2) (0 to 65535) (It is unsigned)
            - boolean(1)

- In Java, true and false are not considered as 1 and 0

- Autoboxing is the automatic conversion of a primitive type to its corresponding wrapper class, and unboxing is the reverse process.  

-1 Widening (automatic casting) / implicit casting (small datattype to big datatype)

-2 Narrowing type casting (manual casting) (big datattype to small datatype)

# Java access modifiers

    - default - accessible in class, other class and same package
              - not accessible in other package
    - private - accessible in class only
    - public - everywhere
    - protected - accessible in class, other class (inherited class) and same package(inherited class)
                - not accessible in other package

# Types of class

   - Static
        - Note: The top level class cannot be static in java, to create a static class we must create a nested class and then make it static.
        - static class is declared with static keyword
        - A static nested class may be instantiated without instantiating its outer class.
        - Inner classes can access both static and non-static members of the outer class. A static class can access only the static members of the outer class.
        - can be inherited
        - objects of static class can be created.
        - if we create a nested static class then the outer class has only one copy of static class.
        - static class can have both static and non static methods. When we create the object of nested static class then the non-static members would have different copies for each object;


        - static method

            - a static methhod can not have static variables
            - static method can not be overridden. Static methods belong to the class rather than any instance, so they are not subject to polymorphism.
            - However, you can hide static methods in a subclass by defining a static method with the same signature in the subclass. This is known as method hiding.

            class Parent {
                static void display() {
                    System.out.println("Static method in Parent");
                }
            }

            class Child extends Parent {
                static void display() {
                    System.out.println("Static method in Child");
                }
            }

            public class Test {
                public static void main(String[] args) {
                    Parent.display(); // Calls static method in Parent
                    Child.display();  // Calls static method in Child


                    Parent obj = new Child();
                    obj.display(); // Calls static method in Parent

                }
            }


            NOTE:
                public static void x(){}
                static public void x(){}

                both are valid



    - Final or constant class
        - class declared with final keyword
        - members are also declared with final keyword
        - final methods can not be overridden
        - can not be inherited by another subclass
        - In Java, declaring a class as final means that the class cannot be subclassed (i.e., no other class can extend this class). This does not automatically make the data members of the class immutable.
        - If you want to prevent the data members of a class from being changed, you need to declare each data member as final. This ensures that once a data member is assigned a value, it cannot be reassigned.

        NOTE - It is mandatory to initialze the final variable
             - final int pi = 31.4; (correct)
             - final int pi; (wrong)

        - final variable can be inherited.

        - Final method

            -When a method is declared as final, it cannot be overridden by subclasses. However, this does not imply that the data members (fields) used within a final method are themselves final.

            - final method can be overloaded but signatures shoudl be different


    - Abstract

        - declared with abstract keyword
        - can have abtract methods and non abstract methods
        - Note: we can not define abstract methods in normal class
        - have to be overridden
        - cannot create objects
        - can have constructor
        - can have static methods
        - can extend another abstract class but cannot override methods

        - varaibles, constructor and inner class can not be abstract

        - Java does not have a keyword explicitly called virtual like C++. However, all non-static methods in Java behave as virtual functions by default. This means that they support runtime polymorphism, where the method that is invoked is determined at runtime based on the object's actual type, not the reference type.

        - NOTE: in c++, virtual functions can not be static

        - abstract method

            - does not have body.
            NOTE: if we want to achieve the functionality of virtaul function like in cpp. we can use super.

    - Inner

        - class inside another class
        - it is also called anonymous class


    - Concrete
        - normal class


    - Pojo
        - POJO stands for "Plain Old Java Object.
        - It is used to implement encapsulation
        - When the data members are private, then it is known as POJO class


    - Singleton
        - When only one object of class is formed

# variables

   - local
        - declared in fixed block of code
        - It is necessary to initialize them if we are using them because these do not have default values

   - instance
        - default value is null
        - decalred in class
        - gets memory only when the object is created
        - not mandatory to initialize. They have deault values
            - integer -> 0
            - float/double -> 0.0
            - string -> null
        - destroyed with the desctruciton of class object
      
   - static

        - In Java, a static variable is allocated memory when the class is loaded into memory by the Java Virtual Machine (JVM).
        - When a class is first loaded into memory, either through the explicit loading by the class loader or implicitly by the JVM when the class is first referenced (e.g., through an instance creation or a static method call), the static variables are initialized.
        - static variables are initialized first, then the main method is called because to call the main method, class is loaded first

    Note: there is no global variable in java


- by default -> 

- class = Scanner (It is not final class)

 NOTE: - only byte, int, short, char and string literals are allowed in switch. ( switch( HERE ) )
                  - Floating literal is not allowed
                  - duplicate cases are not allowed
                  - input literal and cases literal should be of same data type 


# declaration and initialization

    - This is correct =>
        - int[] arr = new int[3];
        - int[] arr = new int[0];
        - int[] arr = {1, 2, 3};
        - int arr[] = {1, 2, 3};
        - int[] arr = new int[] {1,2,3,4};

    - This is incorrect =>
        - int[3] arr = {1, 2, 3};
        - int arr[3] = {1, 2, 3};
        - int[] arr = new int[4] {1,2,3,4};
        - int[] arr = new int[];
        = int arr[3] = new int[];

- defalut value of int array = 0;
- defalut value of float array = 0.0;
- defalut value of char array = null;
- defalut value of boolean array = false;

# constructor
  
    - it can not be declared as final, static, abstract and synchronised.
    - private constructor can not initialize object outside the class but inside it can be done.
    
    - types
        - default
        - parameterised
        - copy

    NOTE: There is no destructor in java. Java has garbage collector.

    - default constructor is created by compiler at the compile time and assigns default values to the data members

    - zero parameterized constructor = default constructor
    - overloading of default constructor is not possible beacause overloading requires differen signature
    - default value of String is null
    - overrding of constructor is not possible

    - Note: if we are declaring a parameterized constructor in a class then it is necessary to declare default constructor also otherwise we won't be able to create object with default constructor.


# super or super()

    - super holds the reference of parent class (default constructor calling)
    - super() calls the constructor of parent class
    - super() is called inside the constructor only and it has to be the first statement in the child constructor.

    - if we have only parameterised const. in base class then it is mandatory to call it in child class's const. using super(arg). and in order to call the default one, we need to declare it and call using super() (without arg).

    - if we do not have parameterised const. in base class, then the default one would be called automatically.
    
    - if we declare both default and parametrized, and do not call anything in the child class, then default wouold be called.

    - a default constructor is not always provided automatically by the compiler. A default constructor is only automatically provided by the compiler if no other constructors (parameterized constructors) are defined. If any constructor is defined (e.g., a parameterized constructor), the compiler does not provide a default constructor unless you explicitly define it.

    - we cannot call the super twice in child constructor. It always have to be the first statment in the child constructor

# Interface

    - interface is a blue print of a class 
    - a class have non-prototype members but the interface have prototype members
    - cannot create object
    - cannot have constructor
    - it does not have any type like final, static etc..
    - it is a pure abstract class
    - Interface doesn't have synchronised methods
    - used for light weight coding 
    -  All variables in an interface are constants (public, static, and final).

    - prototype members

        - prototype method
            
            - same as abstract method   
            - we have to use access modifiers with them
    
    - one interface extends another interface(not implements)

    - interface represents loose coupling

# Interface in JDk 8 version
 
    - updates were made in java interface like
    - interface can have non prototype method as well.
    NOTE: they have to be decalred with default keyword

# Interface in JDk 9 version

    - can have static method

    NOTE: in interface, static memnbers are only called by interface name, not by the object of the class that implemets that.

    - do not declare default and static together

    - can have privte method
    - can have final variable
    
# Polymorphism

    - Compile time

        - method overloading
        Note: Java does not support operator overloading to avoid complexity but '+' is allowed to add to strings as it is a exception

    - Runtime 

        - method overriding
        
        NOTE: acc. to c++, function overriding using virtual function and pure virtual function
