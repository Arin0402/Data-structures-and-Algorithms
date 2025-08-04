# Rules to Declare a Variable

    A variable name can consist of 
    A-Z, a-z, 0-9, _ , $
    
    The first character must not be a digit.
    Blank spaces cannot be used in variable names.
    Java keywords cannot be used as variable names.
    Variable names are case-sensitive.
    There is no limit on the length of a variable name but by convention, it should be between 4 to 15 chars.
    Variable names always should exist on the left-hand side of assignment operators.

    Total java keywords = 50

    const *
    goto *
    transient -  is used to indicate that a field should not be serialized.

    - * -> not used
        
## Type of languages

    - low level languages (Machine lang, assembly lang)
    - high level languages (c, c++, Java etc)

# datatypes

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

    - userdefined
        - Array
        - string
        - etc

    - calculate range of datatypes = -2^n-1 t 2^n-1 -1 (n = no. of bits)
    - java does not suppport long double data type
    - String is user defined datatype
    - In Java, true and false are not considered as 1 and 0
    - char size in java is 2bytes(16bits) but in c/cpp it is 1 byte. It is because java supports Unicode whereas lateral supports ascii.

    - in Java 10 and later, Java allows local variables to be declared with var, where the compiler infers the type. variables can primitive data types, arrays, user defined classes etc.var cannot be used for fields (class or instance variables), method parameters, or return types. It is only for local variables inside methods, constructors, and initialization blocks.  

    - Autoboxing is the automatic conversion of a primitive type to its corresponding wrapper class, and unboxing is the reverse process.  

    - Wrapper classes in Java are classes that encapsulate primitive data types into objects. This allows primitives to be used in contexts where objects are required, such as in collections and generics.  

# Typecasting

    - two types

    -1 Widening (automatic casting) / implicit casting (small datattype to big datatype)

        byte -> char -> int -> float -> double

        ex:
            char x = 65;
            int y = x;

            SOP(y) // output = 65;

            // char is 2 bytes and int is 4 bytes that's why it is possible

    -2 Narrowing type casting (manual casting) (big datattype to small datatype)

        double -> float -> int -> short -> byte

        int x = 65;
        char y = (char)x;

        SOP(y) // output = A

        IMP NOTE:

        - if we are converting integer to byte and the value of interger is > 127 and < 256 then the output would be (val - 256).

            ex- int a = 240;
                byte b = (byte)a;

                System.out.println(b); = -16 (240 - 256)

        - if the value is >= 256, then output would be (val%256)

            ex- int a = 270;
                byte b = (byte)a;

                System.out.println(b); = 14  (270%256)

# Errors

    - syntax error
    - runtime error - exception
    - logical error - bug/fault/wrong logic
    - semantic error/reference error - sytanx is correct but meaning is incorrect like if we write code after return statement, then syntax wise it is correct but semantic wise wrong
    - linker errror - unable to find the address of a file

# History of JAVA

    - start from 1991
    - company name - sun microsystems    
    - current version - JDK24
    - stable version - JDK21

# Java editions

    - J2SE - Java 2 standarad edition(core java)
    - J2EE - Java 2 enterprise edition(advanced java)
    - J2ME - Java 2 macro/mini edition

# features of java

    - secure -> does not support pointers and works on byte code
    - multithreading
    - Distributed - RMI or Java internet application
    - Interpreted - java can be converted to kotlin
    - simple architecture
    - Dyamic - Servlet, JSP
    - Portable
    - Java is an architecture neutral language

# When we say Java is platform independent, what de we mean ?

    - Basically when we compile the Java code, the java compiler converts it to byre code which is just as .class file.
    - There are two compilers. Java compiler and JIT compiler
    - The Jit compiler present in JVM converts the bytecode to machine code.
    - The Java byte code is platform independent but the JVM is platform dependent.
    - For each OS, we need different JVM.
    - thus we can run the byte code on any machine

# Java Virtual Machine (JVM)

    - The JVM is an abstract computing machine that enables a computer to run a Java program. It provides the environment in which Java bytecode can be executed.
    - It consists of Bytedcode loader/class loader, bytecode verifier and JIT(Just-in-time) compiler (converts byte code to machine code)

# Java Runtime Environment (JRE)

    The JRE is a package of software that provides the necessary runtime libraries to execute Java programs. It includes the JVM, along with libraries and other components to run applications written in Java.
    Pre-compiled classes that Java programs can use. These include core libraries like java.lang, java.util, java.io, etc.

# Java Development Kit (JDK):

    A superset of the JRE. It includes everything in the JRE, plus tools for developing, debugging, and monitoring Java applications (e.g., javac, javadoc, jdb).

- command to compile a java file -> javac FILE_NAME.java
- command to run byte code -> java CLASS_NAME

- NOTE: filename and class name can be different only if the class is non public. we compile using file name and we riun the compiled code using classname
    - if the class is public like public test {}, then file name and class name should be same

- if there are 5 classes in a program then 5 .class files would be formed but .exe file would be single only

# Types of class loaders

    - primordial - default class loader
    - non-primordial - user defined class loader

# main method

    - main method is user definexd function but the signature(name and parameters) is predefined. we can not change them

    - In Java, a method signature consists of the method's name and the parameter list (types and order of parameters). The method signature does not include the return type, access modifiers, or exception declarations.

    - For overloading, Parameters should be differnt and name shoudld be same
    - Overlaoding is not considered when only the return type is changed
    - public, private, etc. don’t affect the method signature
    - static, final, modifiers like these are not considered part of the signature        
    - throws IOException, etc., are ignored for method signature

- class names can start with both capital and small

# c# is both procedural and object oriented

# Marker interface
    - An interface with no methods defined in it.
    - It just marks a class with a special property.

# Serializable interface has zero methods defined in it so it is a marker interfce

    The Serializable interface in Java is a marker interface that allows an object to be converted into a byte stream, which can then be:

        saved to a file
        sent over a network
        stored in memory
        or later reconstructed (deserialized) into the same object

# Java does not support copy constructor ditectly because it does not have pointers

    - we can implement copy constructor in java
    - in cpp

        className obj1 = obj would create new object obj1 with shallow copy
    
    - but in java, this would only create a new reference variable that would store the address.
        
        - to create a new object, we can do

            - ClassName obj1 = new ClassName(obj);
            
            - (implement copy constructor in class)

    - In Java, constructors themselves cannot directly have default values for parameters like in C++.

# Java access modifiers

    - default - accessible in class, other class and same package
              - not accessible in other package
    - private - accessible in class only
    - public - everywhere
    - protected 
        - accessible in class
        - Same package
        - Subclass in another package
                    

# Java does not have destructor because Java relies on a garbage collector (GC) 

# static keyword

    - static memory allocation
    - fixed memory allocation
    - pre momory allocation
    - can be accessed by classname and object name

    - Java main method gets static memory allocation that's why we use static keyword with the main function
    - Main is not a keyword in Java

# lang is the Java default package

# IMP - JVM accepts the main method to be of excat signature i.e public static void main(String[] args).

# If we do not write the String[] args, then JVM would not recognize it as a starting point

# We can override the main method. like public static void main(int a, int b).

# default size of Empty class = 1 byte

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

            - a static methhod can not have static variables Because static means "exists once per class" But local variables exist only during method execution.
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
        - Member variables are not final by default                        
        - final methods can not be overridden
        - can not be inherited by another subclass
        - In Java, declaring a class as final means that the class cannot be subclassed (i.e., no other class can extend this class).
        - If you want to prevent the data members of a class from being changed, you need to declare each data member as final. This ensures that once a data member is assigned a value, it cannot be reassigned.

        NOTE - It is mandatory to initialze the final variable
             - final int pi = 31.4; (correct)
             - final int pi; (wrong)

             - We can intialize it in constructor also but only once

        - final variable can be inherited.

        - Final method

            -When a method is declared as final, it cannot be overridden by subclasses. However, this does not imply that the data members (fields) used within a final method are themselves final.

            - final method can be overloaded but signatures shoudl be different


    - Abstract
        
        - Note: we can not define abstract methods in normal class
        - have to be overridden
        - cannot create objects
        - can have constructor        
        - can extend another abstract class but cannot override methods

        - varaibles, constructor and inner class can not be abstract

        - What kind of variables Abstract class have ?

            - An abstract class can include:

                Instance variables
                Static variables
                Final variables

                Any access modifier (private, protected, public)
            
            - If we declare the variable with the same name in child class. It is hidden, not ovverridden. 
            - It means that binding is done at the compile time. So if we call the variable using the Parent's reference, then the variable of parent class would be called. Here parent is an Abstract class.        

        - What kind of methods can Abstract class have ? 

            -   Abstract                =  declared with abstract keyword
                Concrete (with body)	= 
                Static	
                Final	
                Private	
                Protected	
                Public

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

# What is an Object

    - An object is an instance of a class
    - It represents a real-word entity having property and behaviour
    - state and identity denotes the property
        - state -> attributes of object (color, mileage etc are state of car object)
        - identity -> unique name of the object (fortuner)
    - functionality denotes the behaviour

# ways of creating objects

    -1 A obj = new A();

    -2 using class.forName()
        - it is defined in java.lang.Class
        - A obj = (A)class.forName().newInstance();
        - newInstance() is same as constructor

    -3 usign clone() method
        - when we want to create the copies of the object

        A obj1 = (A)obj.clone();
                
        - using clone() method, a new object is created without using constructor

    - 4 using deserializarion

        - we can create serialization and deserialization object
        - When we want to create deserialization object then deserialization interface is implemented
        Note: deserialization interface does not have any method

# tokens

    - Smallest individual units in java program is called tokens
        char a = 'A';

        char -> keyword
        a -> identifier
        = -> operator
        'A' -> constant/literal
        ; -> symbol

        - all of these are token

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

# What is literal

    A literal is a fixed value that you directly type into your code — it represents constant data that Java understands at compile time.

# String is not a datatype, it is a class type/reference type


## Explaining System.out.println("");

    - System is a final class from the java.lang package.
    - System has a final static field named out.
      out is a reference to an instance of PrintStream, which is used for outputting data to the console.
    - PrintStream is a class in the java.io package.
      It provides methods to print various data types, such as print and println.

    - Different print methods

        - print() used for single line statement
        - println() new line
        - printf() used for single line statement but it executes with format string like %d, %s etc

            System.out.printf("%d", 1);

    - System.out -> it is known as standard out stream

# assign System.out to a user defined reference variable

import java.io.printstream

class Test{

    PSVM(String[] args){
        Printstream M = new PrintStream(System.out);

        M.println("abc");
    }

}

# input from user

    - package = util
    - class = Scanner (It is not final class)
    - System.in = standard input stream
    - methods
        - next() - read value of string
        - nextInt()
        - nextShort()
        - nextLong()
        - nextByte()
        - nextFloat()
        - nextDouble()
        - nextBoolean()

    - Scanner s = new Scanner(System.in)

#  Why System.in.nextInt() doesn't work:

    - System.in is of type InputStream

    - InputStream only provides byte-level methods like:

    - read(), read(byte[]), close()

    - It does not have high-level parsing methods like nextInt().

    - To get methods like nextInt(), you must use a parser class like Scanner:

# operators

    - Unary operators (1 operand)
        - increment(++)
            - preincrement
            - postincrement

        - decrement(--)
            - predecrement
            - postdecrement

    - Binary (2 operand)

        - airthmetic -  + - * / %

            - * / % have higher precedence than + -
            - if same precedence operator comes than process from left to right

        - relational - > < <= >= == !=
        - assignment =
        - logical && || !
        - bitwise & | ^ >> << ~(bitwise complement operator)

            - to convert a number n into negtion , short formula is -(n+1).
            - ex
                    int n = ~12;
                    SOP(n) // output = -13

            - if the no. is negative then answer is positive and vice versa


    - NOTE: precedence of these operators (https://www.javatpoint.com/java-operator-precedence)


    - ternary operator OR conditional operator (3 operand)
        ? :

    NOTE: Java does not support sizeof operator because java uses standard size of memory

    NOTE: ex-

        int i = 1;

        int j = ++i + ++i;

        System.out.println(j); // output = 5

        - It is processed left to right

    - instanceof operator

        - it is also called comparision operator
        - it is used to check if the instance or object of a particular class has been initialised or not

        class A{

        }
        class B extends A {

            A obj = new B();
            SOP(obj instanceof A) // o.p = true

            B obj = new B();
            SOP(obj instanceof A) // o.p = true

            A obj = new A();
            SOP(obj instanceof B) // o.p = false

        }
        
# control statement

        - switch control statement

            NOTE: - only byte, int, short, char and string literals are allowed in switch. ( switch( HERE ) )
                  - Floating literal is not allowed
                  - duplicate cases are not allowed
                  - input literal and cases literal should be of same data type 
                  

                  ex -
                    switch('A'){
                        case 1:
                            SOP("HI");
                            break;
                        case 65:
                            SOP("HELLO");
                            break;
                    }

                    // o.p = HELLO ('A' is converted to integer)


        - iteration control statement

            - while
                - this works on boolean condition

                    while(1) -> this is not allowed in Java as 1 is integer
                    whilr(true) -> this is allowed

            - do while
            - for
            - for each

        - Jump control statement

            - continue
            - break

            - ex

                if(true){
                    SOP("HI");
                }
                else{
                    SOP("HELLO")
                    break;
                }

                - This would give error, as the programis compiled first and we cannot use break other than loops and switch.

            - IMP ex - we can use break in scope like this also

                public void myMethod() {
                    outer:
                    {
                        System.out.println("Start of block");

                        if (true) {
                            break outer;
                        }

                        System.out.println("This line will not be printed if above sondition is true");
                    }

                    System.out.println("End of method");
                }

# Types of method

    - predefined
    - user defined

    - by default calling of method is call by value

# Array

    - it is an object in java
    - memory is alloacted at run time
    - derived datatype
    - secondary datatype
    - it is a static linear data structure
    - cannot modify the size

# how to find legth of array

    1. length = It is a final varaible which holds the length of the array
    2. length() = It is s method of String class. Returns the length of the string


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

# return array from function

    int[] m(){
        return new int[3];
    }

    int arr[] = m();


# In Java, everything is pass by value. When we pass the object into a function, it's reference(address) is passed which it self is a value. Changing the refernce will change the original object. 

    - if assign the reference to a nwew object in the function, then it would not affect the original object.

        void changeReference(MyObject o) {
            o = new MyObject(20); // This changes the reference to a new object
        }

        PSVM(String[] args) {
            MyObject obj = new MyObject(10);
            changeReference(obj);
            System.out.println(obj.value); // Output: 10
        }

    - this same goes wiht cpp, when we create object using new keyword.

# Wild pointer in c/cpp

    A wild pointer in C or C++ is a pointer that has not been initialized to a valid memory address. Using a wild pointer can lead to undefined behavior, including program crashes or data corruption, as it may point to an arbitrary and potentially restricted memory location.

    int* ptr; // Wild pointer, uninitialized

# OOPS conscepts

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

# Inheritance

     - Important Points
        Increasing Visibility: When overriding a method, you can change the access modifier to one with greater visibility. Thus, protected can be overridden to public.
        
        Decreasing Visibility: You cannot override a method and reduce its visibility. For instance, a public method in the base class cannot be overridden with a protected or private method in the derived class.

    - Constructor is not inherited

    - features
        - code reusablity
        - runtime polymorphism
        - abstraction
    
    - types

        there are 5 types but java directly supports only 3 and indirectly supprots 2

        - single lvl        
        - multi lvl
        - multiple/multipath (not supported)

            - in cpp we have scope resolution operator to avoid the ambiguity but in Java, we don't have.
            - It can be achieved through interface  

        - hybrid (not supported)
         
            - not supported due to diamond problem
            - can be done through interface
            -                        interface
                                    /       \
                    (extends)     /          \ (extends)
                            interface       interface        
                                  \         /
                                   \       /
                                    class (implements)
                                    

        - hierarchal


# super or super()

    - super holds the reference of parent class (default constructor calling)
    - super() calls the constructor of parent class
    - super() is called inside the constructor only and it has to be the first statement in the child constructor.

    - if we have only parameterised const. in base class then it is mandatory to call it in child class's const. using super(arg). and in order to call the default one, we need to declare it and call using super() (without arg).

    - if we do not have parameterised const. in base class, then the default one would be called automatically.
    
    - if we declare both default and parametrized, and do not call anything in the child class, then default wouold be called.

    - a default constructor is not always provided automatically by the compiler. A default constructor is only automatically provided by the compiler if no other constructors (parameterized constructors) are defined. If any constructor is defined (e.g., a parameterized constructor), the compiler does not provide a default constructor unless you explicitly define it.

    - we cannot call the super twice in child constructor. It always have to be the first statment in the child constructor

# Abstraction

    - Absttraction is a process of data hiding
    - It can be achieved by two ways

        - abstract class (data hiding 0 to 100%)
            - achieved through methods
        - interface (data hiding 100%)

# Overriding 

    NOTE: in overriding, the squence of arguments should also be SAME.


# Interface

    - interface is a blue print of a class 
    - a class have non-prototype members but the interface have prototype members
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

    NOTE: in interface, static memnbers are only called by interface name, not by the object of the class that implemets that

    - do not declare default and static together

    - can have private method
    - can have final variable

# Serialization and deserialization
    
    Serialization
        
        - conversion of object into byte stream 
        - it is done through serializable interface which is defined in io package

    Deserialization

        - conversion of byte stream into object
        - it is done through deserializable interface which is defined in io package

    Note: methods(non-prototype) are not defined in serializable interface 

    Advantage
        - object save/object persist


# Polymorphism

    - Compile time

        - method overloading
        Note: Java does not support operator overloading to avoid complexity but '+' is allowed to add to strings as it is a exception

    - Runtime 

        - method overriding
        
        NOTE: acc. to c++, function overriding using virtual function and pure virtual function

# Factory method

    - when the constructor of the class is private, then in order to use it, factory method is used.

    - In a class, when the method is declared as static and type of the method is class then it is called factory method

# Object casting
    
    - upcasting (widening) (implicit casting)   
        - when child class object is initialised in parent class reference variable

    - downcasting (Narrowing) (explicit casting)

    - why is it used ?

        - This improves code reusability and maintainability

        - You can write more generic and reusable code that works with the superclass type but can handle any subclass object.

        - when in a is-a relationship , the method of parent class is not acquired in child class due to same methods in both parent and child

        - it used to reuse the property of parent class

    NOTE: WE can not call the new methods declared in the child class using the reference of parent class.

        - Parent obj = new Child();
        obj.parentMethod();   // OK
        obj.childMethod();    // ❌ Compile-time error (not visible to Parent)

        - Here childMethod() is declared in child class only

        - Inorder to call the child class method, we have to type cast it

            Parent obj = new Child();   // Upcasting
            ((Child)obj).childMethod(); // ✅ Now you can access child methods



# Encapsulation 

    - Encapsulation is the process of hiding the internal details of an object and only exposing what is necessary.
    - It means wrapping data (variables) and methods (functions) together in a single unit — a class — and restricting direct access to some parts of it.
    - data members are dcalred private and public methods are exposed to access them. (getter and setter metods)

    
# String in Java

    - two ways of creating

        - using literal

            String s = "RAM";

            - when we declare string like this, then object is not created.
            - it is more memory efficient.

        - using new keyword

        - When you create a string using a literal, Java checks the string pool (a special area in memory) to see if an identical string already exists. If it does, it uses the existing string; if not, it creates a new one in the pool. This approach is generally more efficient because it avoids creating duplicate string objects. But by using new, it always creates new object.

    - methods

        - concat()
        - isEmpty() = if the string has been initialised or not.

            String s = "";
            s.isEmpty() = true

        - length()
        - trim() = remove start or end white space
        - charAt()
        - replace(oldchar, newChar)
        - indexOf()
        - toUpperCase()
        - toLowerCase()
        - split() 
            
            - to break the string based on certain character
            
            string s1 = "I am programner";

            string s2 = s1.split("\\s");

            for(Strins r : s2) SOP(r);

            NOTE: for more than one space, use "\\s+"

        - equals()
        - equalsIgnoreCase()

        - valueOf()
            - converts any value to string

        - compareTo()

            - compares lexicographically 
            - returns ans in zero (string matches) and non zero (not match (-ve and +ve based on ASCII values)).

        - lastIndexOf(char/word, indexbefore (optional))

            -  String str = "Hello, World!";

            // Find the last occurrence of 'o'
            int lastIndex1 = str.lastIndexOf('o'); // 8

            -  String str = "Hello, World!";

            // Find the last occurrence of 'o' before index 5
            int lastIndex1 = str.lastIndexOf('o', 5); // 4


        - hashCode()

            - to get the hashcode of the string

# Difference between mutalble and immutable string

    - String, StringBuffer, StringBuilder implements charSequence interface whihc is found in java.lang package

    - String is immutable

    - StringBuffer and StringBuilder are mutable

    - StringBuffer 
        - It is synchronised means thread safe.
        - It means two threads can not call the methods of stringBuffer at the same time
        - less efficient 
        - introduced in java 1.0
        - ex  StringBuffer s = new StringBuffer("Hello");
              s.append("Ram");

              time taken = 200 ms   


    - StringBuilder
        - It is not synchronised means thread unsafe.
        - It means two threads can call the methods of stringBuilder at the same time
        - more efficient
        - introduced in java 1.5
        - ex  StringBuilder s = new StringBuilder("Hello");
              s.append("Ram");

              time taken = 20 ms   

    
    - advantage of immutable string

        - classloader
        - thread safe
        - heap space efficiency
        - security


# Exception handling

    There are two types of abnormalities that can occur

    - Exception 
    - Error

    - these are classes which are inherited from Throwable class (java.lang package)    

    java.lang.Object
    └── java.lang.Throwable
        ├── java.lang.Error
        └── java.lang.Exception
                ├── java.lang.RuntimeException
                └── other checked exceptions


# Types of exception
    
    - checked 
        - those exceptions which are directly inherited from Exception class
        - RuntimeException      
        - IOException
        - SQLException
        - ClassNotFoundException

    - unchecked

        - those exceptions which are not directly inherited from Exception class
        - these are inherited from RuntimeException class       
        - Airthmetic Exc.
        - Nullpointer Exc.
        - Numberformat Exc.
        - Indexoutofbound Exc.
            - ArrayIndexout Exc.
            - StirngIndexout Exc.

# Types of error

    - these can't be handle, if they occur than program stops
    - StackOverFlow error
    - Virtiualmachine error
    - outofmemory error

# Exception handling keywords in Java

    - try
    - catch
    - finally
    - throw
        
        - It is used to explicitly throw a single exception from a block of code (can be a method)
        -ex:  

        void x(){
            throw new ArithmeticException("some text");
        }
        
    - throws

        - The throws keyword in Java is used in the method signature to declare that a method might throw one or more exceptions.

        - ex:   void riskyMethod() throws IOException, SQLException {
                    if (Math.random() > 0.5) {
                        throw new IOException("IO error occurred");
                    } else {
                        throw new SQLException("SQL error occurred");
                    }
                }

        NOTE: 
            - We cannot directly throw multiple types of checked exceptions from a method without using the throws keyword in the method signature. In Java, if a method can throw checked exceptions (subclasses of Exception), you must declare them using throws. This informs the caller of the method that they need to handle those exceptions.

            - We can throw multiple unchecked exceptions without using throws:



    NOTE: try does not work alone. Works either with catch or finally or both

    - syntax

    try {

    }
    catch(Exception obj){

    }

    NOTE: - We can't write in the middle of the try , catch, finally blocks.
        like 
            try{

            }
            // some code..
            catch(Exc e){

            }

            this is not allowed
 
        - If we do not use the catch block, then the code after finally will not be executed.
        - If we use the catch block, then the code after finally will be executed.

        - order should be same of try, catch and finally


# Multithreading

    - Multithreading in java is a process of executing multiple threads simultaneously

    - A thread is a light weight, subprocess, the smallest unit of processing .

    - Multi tasking is achieved either by multithreading or multiprocessing 

# Advantages of Java multithreading

    - It does not block the user
    - you can perform many operations together and save time and memory(share memory)
    - threads are independent
    - threads use context switching

# Implementaion on multithreading

    - two ways
        - Thread class
        - Runnable interface

    - difference bw Thread class and RUnnable interface

        - if we extend the Thread class then our class can not extend other class because java does not support multiple/multipath inheritance

        - We can achieve basic fucnctionality of Thread by extending Thread class bcz it provodes some inbuilt methods yield()/... so many methods which are not available in Runnable interface.

        - using Runnable will give you an object that can be shared amongst multiple threads

# Thread class
    
    - predefined class in Java
    - present in java.lang package

    - run() method

        - it is used to create a new thread().
        - it is a class method
        
    - start() method

        - it is used to run a thread 
        - it is a class method

    - ex: 
                  
        class A extends Thread {

            public void run(){
                System.out.println("Hello");
            }
        }

        class B {
            public static void main(String[] args) {

                A obj = new A();
                obj.start();
                        
            } 
        }

# Thread lifecycle methods

    Thread Lifecycle
    A thread in Java goes through various stages during its lifecycle:

    - New: A thread is in this state after being created, but before the start() method is called.

    - Runnable: The thread is ready to run and waiting for the CPU to allocate time for its execution.

    - Blocked/Waiting: The thread is waiting for a monitor lock or waiting indefinitely for another thread to 
    perform a particular action.

    - Timed Waiting: The thread is waiting for another thread to perform an action for a specified waiting time.

    - Terminated: The thread has exited, either because it has completed its task or because an exception has terminated it.


    Key Points

    - Thread Lifecycle: Once a thread has completed its task, it transitions to the TERMINATED state and cannot be restarted.

    - Creating New Thread Instances: To run a task multiple times, create new thread instances each time you need to execute the task.

    - Exception Handling: Calling start() on a terminated thread will result in an IllegalThreadStateException.   

    - In the above example, we can not call obj.start() multiple times. 

# Thread methods

    - run()
    - start()
    - sleep()        
    - yield()
        
        - yield() is a way to suggest to the thread scheduler that the current thread is willing to pause and allow other threads to execute.
        - The scheduler might ignore this hint, so yield() is not guaranteed to have any effect. 

    - getId()

        - deprecated 

    - setPriority()
    - getPriority()
        
        - set the priority of the thread
        - on the scale of 1(Thread.MIN_PRIORITY) to 10(Thread.MAX_PRIORITY)
        - normal(default) is 5 (Thread.NORM_PRIORITY)

    - setName()
    - getName()
    - currentThread()

        - returns a reference to currently executing thread object

        class A extends Thread {
            public void run(){                
                System.out.println(Thread.currentThread().getName());        
            }
        }

        PSVM(){
            A obj = new A();        
            obj.start();                
        }


    - join()

        - The join() method in Java is used to pause the execution of the current thread until the thread on which join() is called has completed its execution. This is useful for ensuring that one thread waits for another to finish before proceeding.

    - isAlive()

        -  check if the thread is alive
        - a thread is considered to be alive when the start() method of the thread has been called and the thread is not yet dead.
        -  a thread is not considered alive after it has completed its execution. Once a thread has finished executing its run() method, it enters the TERMINATED state and is no longer alive

    - stop()    

        - deprecated 
        - stop a particular thred
        

    - destroy()

        - deprecated 
        - it has never been part of the Java Thread class. Instead, it was part of the ThreadGroup class 

    - suspend()

        - Deprecated
        - The suspend() method in Java was used to pause the execution of a thread, but it is deprecated due to the potential for deadlocks and other synchronization issues.

    - resume()  

        - deprecated
        - The resume() method in Java was used to resume a suspended thread, but it is deprecated due to the same concerns as suspend()

    - interrupt()

        - The interrupt() method in Java is used to interrupt a thread. Interrupting a thread is a way to signal that the thread should stop what it's doing and do something else. However, it's up to the thread to handle the interruption properly, as the interrupt() method does not forcibly terminate the thread.


    - activeCount()
    - checkAccess()
    - holdsLock()

        - The holdsLock() method is a static method that checks if the current thread holds the monitor lock on a specified object.

        - Returns true if the current thread holds the lock, otherwise false.

    - dumpStack()
    - getState()
    - notify()

        - The notify() method in Java is used to wake up a single thread that is waiting on the object's monitor. This is part of Java's thread synchronization mechanism and is essential for coordinating the execution of multiple threads.

    - notifyAll()

        - The notifyAll() method in Java is used to wake up all threads that are waiting on the object's monitor. This is part of Java's thread synchronization mechanism and is essential for coordinating the execution of multiple threads.

    Note: It is must to use exception handling while usign multithreading.
        The wait(), notify(), and notifyAll() methods are provided by the Object class in Java. 

# create thread using runnable interface

    - it has run() defined as prototype
    NOTE: runnable interface does not have start() method

    -ex:

    class MyRunnable implements Runnable {
        public void run() {
            System.out.println("Thread is running");
        }
    }

    class Main {
        public static void main(String[] args) {

            // pass the object of MyRunnable class into thread class because Runnable interface does not have start() method 

            Thread thread1 = new Thread(new MyRunnable(), "Thread-1");
            thread1.start();

        }
    }

# Package

    - collection of similar classes and interface is called package
    - package
        L sub-package
            L classes and interfaces

    - ex: java.io.Printstream

        java = package
        io = sub-package

# Types of packages

    - two types

        - predefined
        - user defined

    - list of pre defined package

        - lang package - use for all primitive data types
        - io package
        - util package - for utility classes like LinkedList or collection classes
        - awt package - for components/containers
        - applet package - for creating applet
        - net package - for supporting networking classes
        - math package - for mathematics related operations
        - sql package - for database connectivity and implementation


# awt package

    - stands for abstract window toolkit
    - awt is a API which is used to create GUI application/desktop App/console app. 
    - Applications made through awt are heavy in nature and OS dependent
    - some of the components are BUtton, Label, checkBox, list etc
    - Container is a component which holds another components
        - types (4)
            - window
            - Frame 
            - Dialog
            - Panel
                - Applet 

        - window container does not support border & menubar
        - panel does not support border, menubar and title
        - frame supports border, menubar and title
        - Dialog 

# Methods for creating GUI app

    - setTitle()
    - setLayout() - for customization of layout
    - setSize(int width, int height) - set height/width of Layout 
    - setVisible() - for visibility (individual app)
    - add() - add components to container
    - setBounds(x-coordinate, y-coordinate, width, height)

# eventhandling

    - It is performed by classes or interfaces
    - the packageName of event handling is event

    - import java.awt.event.className
                or
    - import java.awt.event.*

    - for buttons, list, Choice(dropdown)
        - the class used is ActionEvent
        - the interface used is ActionListener
        - the method used is actionPerformed
        
    -ex 

        class My extends Frame implements ActionListner{

            Button b1 = new Button("Submit")
            Label l1 = new Label();

            b1.addActionListner(this);

            public void actionPerformed(ActionEvent e){

                if(e.getSource() == b1){
                    l.setText("Infique")
                }

            }
        }
        
# Checkbox

    - ItemListner is used to perform event handling on checkbox 

    - ItemListner is an Interface
    - ItemEvent is a class
    - method used is itemStateChanged(ItemEvent e)

    - types
     
        - Checkbox()
        - Checkbox(name, state(true/false))
        - Checkbox(name, groupname state(true/false))

# TextArea

    - Event - KeyEvent 
                L KeyTyped
                L KeyReleased
                L KeyPressed

    - Listner = KeyListener

# RadioButton

    - types
     
        - RadioButton()
        - RadioButton(name, state(true/false))
        - RadioButton(name, groupname state(true/false))

    - some methods

        - getText()
        - setText()
        - setEnabled()
        - setIcon()

# Swing

    - Swing is a java API which is used to create GUI/Desktop apps

    NOTE: It is a subpackage of javax. ( import javax.swing.className or javax.swing.*)

    - OS independent applications
    - light weight
    - WindowListener is present 
    - All event class, listners, containers and components are acquired by AWT

    - Some events

        - TextListener - interface
          Textevent - class
          textValueChanged - method
          - used in textfield/textarea

        - WindowListener
          WindowEvent
          - methods 
                - windowOpened
                - windowClosing
                - windowClosed
                - windowIconified
                - windowDeiconified
                - windowActivated
                - windowDeactivated

        - MouseListener
          MouseEvent 
          - methods 
                - mouseClicked
                - mousePressed
                - mouseReleased
                - mouseEntered
                - mouseExited

        - FocusListener
          FocusEvent  
          - methods 
                - focusGained
                - focusLoss


        - ContainerListener
          ContainerEvent
          - methods 
                - componentAdded
                - componentRemoved
                
        - ComponentListener
          ComponentEvent
          - methods
                - componentHidden
                - componentMoved
                - componentResized
                - componentShown  

        - WheelListener
          WheelEvent
          - methods
                - mouseWheelMoved 

# JDBC (Java Database connectivity)

    - package java.sql.*
    - it is used to establish connection with database and execute query
    - it is an API
    
    - Architecture

           Java application
                |
            JDBC API
                |
            JDBC Driver
                |
            Databases      

    - JDBC steps 

        - Register driver
        - create connection
        - create statement(execute query)
        - close connection

    - types of JDBC architecture

        - two tier (direct application to database)
        - three tier  (appliction - middleware - database)

# JDBC driver

    - JDBC driver runs on client machine
    - JDBC driver understands the protocols and helps to interact with database
    - It acts as a bridge between the application and the database, translating Java calls into database-specific calls and vice versa. 

    - types

        - JDBC - ODBC (open database activity) driver
        - Native-API driver
        - Network protocol driver
        - thin driver

    - working steps of JDBC
     
        - step 1. Register driver 
            
            - class used = Class
            - method used = forName

            like Class.forName("DriverName");

        - step 2. create connection

            - interface = Connection
            - class = DriverManager
            - method = getConnection("url", "user", "password");

            like Connection obj = DriverManager.getConnection();

        - step 3. create statement  
            (Exchange data bw app & database with sql queries)

            - interface = Statement
            - method = createStatement()

            like  Statement s = obj.createStatement();

        - step 4. close connection & statement

            - method = close()

            like obj.close()
                 s.close()

# create statement methods

    1. boolean execute("sql query")

        - DDL successfully executed or not
        - returns True/False

        - used for creating structure/table

    2. ResultSet executeQuery("sql query")

        - for DQL queries
        - used for select queries
        - returns data as a ResultSet

    3. int executeUpdate("sql query")

        - for DML (insert, update, delete)

# JDBC applications

    - Java desktop applications (windowm, GUI, console)
    - Servlet - application
    - JSP appliction
    - EJB - Enterprise Java Bean application

# Servlet

    - Servlet is a java technology which is used to create dynamic webpages/websites.
        or
    - Servlet is a java API which is used to create dynamic webpages/websites.
        or
    - It is a program that runs on server which is used to create dynamic webpages/websites.


    - CGI Shell 

        - stands for Common Gateway Interface
        - before servlet, CGI was used.
        - it is used to create dynamic response.
        - it is a scripting program
        - it is platform dependent. written in c/c++ or perl lang.

        - Disadvantage

            - low performance
            - for each request, a new process is created and each process is handled by a seperate CGI program
            - max cpu load
            - platform dependent
            - response time is maximum

    
    - Advantages of Servlet
     
        - high performance
        - for each request, a new thread is created. All these threads are part of a single process. This single process is handled by servlet program
        - portability
        - security
        - robust

    - servlet provides many classes and interfaces

    - packages  

        - javax.servlet.*
        - javax.servlet.http.*

    - various classes and interfaces are present in these packages as folowing

        - Servlet                    (interface) (javax.servlet)
        - ServletRequest             (interface) (javax.servlet)
        - ServletResponse            (interface) (javax.servlet)
        - GenericServlet             (class)     (javax.servlet)
        - HttpServlet                (class)     (javax.servlet.http)
        - HttpServletRequest         (interface) (javax.servlet.http)
        - HttpServletResponse        (interface) (javax.servlet.http)
        - Filter                     (interface) (javax.servlet.http)
        - ServletConfig              (interface) (javax.servlet.http)

    - servlet is created using 

        - Servlet                    (interface) (javax.servlet)        
        - GenericServlet             (class)     (javax.servlet)
        - HttpServlet                (class)     (javax.servlet.http)

        ex -

            class MyServlet implements Servlet{

            }
                OR

            class MyServlet extends GenericServlet{

            }
                OR

            class MyServlet extends HttpServlet{

            }


# Servlet architecture

    - webbrowser sends request to webserver
    - webserver sends request to servlet container
    - many programs are running in servlet container
    - any one of the program caters the request
    - it send back response to the webserver
    - webserver sends back response to web browser

    
    - servlet container

        - it is also called servlet engine/web container
        - servlet engine provides runtime environment

    - services provided by servlet container

        1. Network service

            - Load servlet class or servlet        
            - load file system
            - provides network services and manage request & respose at the network

        2. Encoding or decoding

        3. Manage servlet life cycle

        4. Security services

        5. Session management

# life cycle of servlet

    - Load servlet or load servlet class
    - initialization servlet or initialization object
    - Request handlling
    - Destroying servlet or object


    - these are the methods which are used in the lifecyle of servlet. These are called inside servlet container
        - init()    
            - called once after the object has been initialized

            public void init() throws ServerException {
                // code
            }


        - service()              
            - called many times
            - it checks the request method types in the request.
            - doGet() and doPost() methods are called by service method

            public void service(HttpServletRequest request, HttpServletResponse response) throws ServerException{                
                // servlet coding is done in this part
            }

            - it is the main method of the servlet.


        - destroy() 
            
            - called once by servlet container
            - destroys the servlet object

            public void destroy() throws servletException{
                //code
            }

# HTTP protocol

    - it is a communication protocol
    - establilsh communication bw client and server
    - default port 80
    - Http is a TCP/IP based protocol
    - it is request or response protocol
    - it is stateless protocol
    - it is application layer base protocol 


    - follwing information is included with http protocol when request is made

        - Analysis source ip address, post, proxy
        - Analysis destination IP address, port no, proxy and protocol
        - the request URI (Uniform resource identifier)
        - the request method and content type 
        - the user agent header
        - the connection control header

    - client requestin methods

        - get 
        - post
        - delete
        - trace
        - put
        - option
        - head

# Differnce bw get and post

    - get 
        - large amount of data can not be sent because data is sent in header
        - get request is not secured bcz data can be explored in URL
        - get request can be bookmarked
        - get request can be idempotent (meaning second request can't be made untill first request has received the response)
        - More efficient
    
    - post
        - large amount of data can be sent because data is sent in body
        - post request is secured bcz data can not be explored in URL
        - post request can not be bookmarked
        - post request is not idempotent

    NOTE: doGet() and doPost() methods are called by service methods
        
    ex: of doGet()

        public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServerException{                
                // coding 
        }

    ex: of doPost()

        public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServerException{                
                // coding 
        }

# Software requirements

    - Server (Apache Tomcat server)
    - JDK
    
    NOTE: Jar file = Servlet-API (This jar file is important)
    
    NOTE: 
        - Web.xml file is used for the mapping of the servlet. without doing thi, servlet wouldn't get called.
        - mapping of all the servlets is compulsory


    - web.xml 

        - it is mapping file
        - it is also called servlet configuration file

# Servlet Http response codes

    - start from 100
    - last code 505

    - 100  continue (request received but response not generated)
    - 101  switching protocols ( server switching the protocols)
    - 200  ok (success)
    - 202  Accepted (request accepted, response processing in progress)
    - 203  Non authentic information (client information is not authentic)
    - 204  No content
    - 205  Reset content
    - 206  Partially content
    - 300  Multiple choice (respone has multiple choice)
    - 301  move permanently (switching links, meaning request link is switched with another link)
    - 302  found (same as 301 but temporary)
    - 303  see other (the request page is found)
    - 305  use proxy (define client request proxy)
    - 307  Temporary redirect
    - 400  bad request (server cannot understand request)
    - 401  unauthorized
    - 402  payment required
    - 403  forbidden
    - 404  page not found
    - 405  method not allowed
    - 408  request timeout
    - 413  request entity too long
    - 414  request url too long
    - 500  Internal server error
    - 502  Bad gateway
    - 504  gateway timeout
    - 505  Http version not supported

# Form methods

    - getParameter() - to read the single value (ex. from textfield)
    - getParameterValue() - to read multiple values (ex. checkboxGroup)
    - getParameterName() - to read the value from list conroller 


# Session tracking

    - In order to establish stateful relationship between client and server, session tracking is used
    - It is used to track information/data record of the client

    - why session tracking ?

        - client and server generally has stateless relationship because they use HTTP protocol
        - Session tracking establishes state relationship

    - sessions are created on server
    - Acc. to Java, session is a object

    - types
        - URL re-writting
        - Cokkie session tracking
        - Session or http session
        - Hidden form field  

# 1. URI

    - uri stands for uniform resource identifier
    - it represent complete link
    - URI is a suerset of URL and URN
    - URI = URL + URN

    - A URI is a string of characters used to identify a resource either by location, name, or both.
    - Example: http://example.com,

    - A URL (Uniform Resource Locator) is a specific type of URI that provides the means to locate a resource  by describing its primary access mechanism,
    - Includes the protocol (scheme), domain, path, and sometimes a query and fragment.
    - Example: http://www.example.com/index.html

    - A URN is a type of URI that names a resource so that it can be identified in a persistent, location-independent manner.
    - Example: urn:isbn:0451450523


# 2. Cookie 
    
    - a cookie is a small text file
    - a cookie is used to track/store/save the user's information
    - it is stored on client side
    - it is craeted on browser
    - it is sent by server

    - ex:  

        Cookie obj = new Cookie(name, value)

            or

        Cookie obj = new Cookie(name)

    - methods

        - setmaxAge() = set the max age of the cookie
        - setname() = set name of the cookie
        - setValue() = set value of the cookie
        - getName() 
        - getValue()
        - addCookie() = add cookie in browser

    - Cookie text file size is 4kb
    - browser supports 20 cookies at a time
    - server can send 300 cookies at a time

# Attributes of cookie

    - name
    - value
    - domain
    - path = Specifies the path within the domain for which the cookie is valid. If not set, the cookie is valid for the entire domain.
    - max age = Specifies the maximum age of the cookie in seconds. If set to a negative value, the cookie is not stored persistently and will be deleted when the browser closes.
    - secure
    - HttpOnly
    - version
    - comment (optional)

# Types of cookie

    - total 5

    - Non-persistent
        - it is temporary cookie
        - it is also called sessin cookie
        - it is only vaild for a single session
        - upon closing the browser, this gets deleted
        - User needs to login in again and again.

    - Persistent    
        - permanent cookie
        - it is valid for multiple seessions
        - it remains even after closing the browser        

    - Third party
        - it is also called tracking cookie        
        - tracks user behaviour        

    - Zombie
        - it is a auto generated cookie
        - it gets autogenerated even after deleting it 

    - Flash cookie
        - it is also called super cookie
        - it is also called shared object cookie
        - created using Adobe Flash software 
        - it is independent of browser

# Disadvantage of cookie

    - if cookies are disabled on browser then session tarcking won't happen
    - only textual information is saved in cookie


# 3. Hidden form field

    - session trackign technique
    - in order to track user information, hidden field is used inside the form
    
    - advantage
        - does not depend on cookie

    - disasvantage
        - session tarcking maintained by server
        - Hidden form field technique demands from on every page
        - track only textual information

# 4. Http session Interface

    - session always creates on server
    - every user has unique id

    - How to get session ?

        - sesison get by public HttpSession getSession()
                        OR
                        get session(boolean)

        - request object is used in order to get the session

            - HttpSession x = request.getSession()

        - set attributes of session

            - x.setAttributes("AB", "RAM");

                AB is name
                RAM is value

    - methods of HTTP Session

        - getId()
            - return the id of the sesison

        - getCreationTime() or public long getCreationTime()
            - return creation time of a particular session

        - getLastAccessedTime() or public long getLastAccessedTime()
            - return the last accessed time of the particular session

        - invalidate() or public void invalidate()
            - return situation of particular session delete or not

        - setAttribute()

        - getAttribute(name)
            - to retrieve single attribute

        - getAttributesNames
            - to retriueve all the attributes  

        - removeAttribute(name)

        - getMaxInteractiveInterval()


    - advantages
        - more secure
        - does not depend on cookie 
        - session maintained by server

    - disadvantage
        -  stores information in text format

# Collections in java

    - In Java, a collection is a framework that provides an architecture to store and manipulate a group of objects. Java Collections provide a well-defined set of interfaces and classes to work with groups of objects. They allow developers to store, retrieve, manipulate, and communicate aggregate data easily.

    - Heirarchy of Collections framework

        - Iterable (Interface)
            - Collecion (Interface)
                - List (Interface)
                    - ArrayList
                    - LinkedList
                    - Vector
                        - Stack
                - Queue (Interface)
                    - PriorityQueue
                    - Deque (Interface)
                    - ArrayDeque
                - Set (Interface)
                    - HashSet
                    - LinkHash
                    - SortedSet (Interface)
                    - TreeSet

    - Collection is present in util package

    - method of Collection Interface

        - public boolean add()
            - Use add() to insert individual elements into a collection.

        - public boolean addAll(Collection obj)
            - Use addAll() when you need to add multiple elements from another collection efficiently.

        - public boolean remove()
            - remove a single element
            - It has two overloaded versions:
                - remove(int index): Removes the element at the specified position in this list.
                - remove(Object o): Removes the first occurrence of the specified element from this list, if it is present.

        - public boolean removeAll(Collection obj);
            - Use removeAll() when you need to efficiently remove a set of elements from a collection

        - public int size()

        - public void clean()
            - The clear() method is used to remove all elements from a collection, making it empty. 

        - public boolean contains(Collection object)
            - search

        - public boolean containsAll(Collection obj)
            - The containsAll() method is used to check if a collection contains all elements of another specified collection

        - public Iterator interator()

            Iterator<String> iterator = list.iterator();

        - public Object[] toArray()

            Object[] array = list.toArray();

        - public boolean isEmpty()

        - public boolean equals( Object obj)
            - The equals() method is used to compare two objects for equality. It is defined in the Object class and can be overridden in custom classes to provide specific equality logic.

        - public int hashCode()

    NOTE:  the Iterable interface has an iterator() method that returns an Iterator. This allows the collection to be iterated over using an Iterator or an enhanced for-loop, providing a standardized way to traverse collections in Java.

    - methods of Iterator interface

        - public boolean hasNext()
            Returns true if the iteration has more elements.
        - next()    
            - Returns the next element in the iteration.
            - Throws: NoSuchElementException if the iteration has no more elements.

        - void remove()

# List collection/Interface

    - Arraylist
        - it can contain duplicte element
        - it is used to store different datatype of elements
        - dynamic memoery allocation
        - it is not synchronized

    - Linked list

        - It provides a doubly linked list implementation.
        - It is not synchronized. This means it is not thread-safe    

        - methods
         
            - public boolean addFirst()
                - insert node at first position

            - public boolean addLast()

            - public boolean getFirst()

            - public boolean getLast()

            - pubic ElementType get(index)

# Vector 

    - it is implemented usign dynamic array
    - Vector is similar to ArrayList

    NOTE: It is synchronized in nature.
    

# Stack

    - it is synchronized and therefore thread-safe for use in concurrent environments.

    methods        
        - push(E item): Pushes an item onto the top of the stack.
        - pop(): Removes and returns the item at the top of the stack.
        - peek(): Returns the item at the top of the stack without removing it.
        - empty(): Tests if the stack is empty.
        - search(Object o): Returns the 1-based position from the top of the stack where the specified object is located; returns -1 if the object is not found

# JSP

    - Java Server Pages
    - JSP is used to create Dynamic website/pages
    - JSP is an extension of Servlet

        - why ?

            - JSP uses implicit objects like out.psint()
            - implicit tags are used in JSP
                - Declaration tag
                - Scriplet Tag
                - JSP expression
                - Java comments
                

    - JSP-API or technology is server side
    - File extension is .jsp
    - JSP tag or custom tag are used in this

    - How JSP more advantageous than servlet

        - JSP is easy to maintain 
            - When we create dynamic webpage using servlet, HTML/XML is used inside java code which is hard to maintain
            - When we create dynamic webpage using JSP, Java code is used inside HTML/XML code which is easy to maintain

        - no need of recompilation or deployment in JSP
            - servlet is compiled again n agin

        - less coding required in JSP

            - Servlet use explicit coding
            - JSP use implicit coding

        - JSP supports entire APIs of Java
            - servlet does not


# Feature of JSP

    - easy to maintain
    - easy coding
    - reduce code length
    - easy database connectivity    
    - powerful, portable, flexible
    

# JSP life cycle

    1. Translation of JSP
    2. Compilation of JSP
    3. Class loading
        - class loader loads the java files

    4. Instantiation
        - Servlet object is created

    5. Initialization
        - Servlet object gets initialized
        - Web container calls the JSPInit() method
        - JSPInit() method is similar to servlet init() method (called only once)

    6. Request Processing
        - _JSPService() method is called by web container in this phase (called multiple times)
        - it is similar to servlet service method        

    7. Destroy of JSP
        - JSPDestroy() method is called by web container (called only once)
        
# JSP packages

    - javax.servlet.jsp   
        - it consists of two interfaces

            - JspPage interface
                - HttpJspPage (sub interface of JspPage)

            NOTE: Servlet is the parent of JspPage

            - JspPage has JspInit() and JspDestroy() methods
            - HttpJspPage has _JspService() method ( underscore means do not override method)

        - it consists of two classes

            - JspWriter
            - JspContext
            - JspFactory
            - JspEngineInfo
            - JspException
            - JspError


    - javax.servlet.jsp.tagext

# Example of Jsp with using scripting elements

    <html>
    <body>
    <% out.println("Hello") %>
    </body>
    </html>

# JSP scripting elements

    - Jsp scripting elements are used to write java code inside html file.
    
    - types

        - 3 types

            - Scriplet Tag OR JSP Scriplet Tag

                - syntax
                    <%  source code %>

                    - it is use for the implementation of Java source in HTML file
                    - For embedding Java code that is executed each time the JSP page is requested.
                    - Variables are declared in Scriplet tag and objects and methods are used.

            - Expression Tag OR JSP Expression Tag

                - syntax
                    <% = statement %>

                    - It is used to define expression or statement
                    -  For embedding Java expressions that are evaluated and included in the HTML output.
                    - we can call method also.
                    NOTE: Semicolon is not used in expression tag.
                    
                    - ex <% = "this is my first jsp prog." %>
 
            - Declaration Tag OR JSP Declaration Tag

                - syntax

                    <% !  code  %>

                    - it is used to declare variable and method.
                    -  For declaring variables and methods that persist for the life of the servlet instance.

                    - ex 
                        <% ! String name = "Rakesh" %>
                        <% = "Welcome = " + name %>

                    - ex declaration of method and usage

                        <% !

                            public inf getId(){
                                return 10;
                            }
                        %>

                        <%
                            int x = getId();
                            out.println(x);                            
                        %>

                        <% = 
                            "My id = " + getId() 
                        %>

# Difference bw Scriplet tag and declaration tag

    - The jsp scriptlet tag can only declare variables not methods.
    - The jsp declaration tag can declare variables as well as methods.


    - The declaration of scriptlet tag is placed inside the _jspService() method.
    - The declaration of jsp declaration tag is placed outside the _jspService() method.

# JSp implicit objects (IMP)

    - jsp implicit objects created by web container
    - There are total 9 implicit jsp objects

    - these are the following

        Object          Type

        out             JspWriter
        request         HttpServletREquest
        response        HttpServletResponse
        config          ServletConfig
        application     ServletContext
        session         HttpSession
        pageContext     PageContext
        page            Object
        exception       Throwable


    - out
        - it is used to print web information
        
        ex: PrintWriter out = getWriter();

        <% out.println("Hi") %>

    - request
        - get client information

    - response
        - get response information from the server

    - config
        -  Represents the servlet configuration. It provides initialization parameters and a reference to the servlet context.

        - String initParam = config.getInitParameter("configParam");

    - session
        - used to set/get session attributes

        - session.setAttribute("User" ,U);

    - pagecontext
        - The pageContext object can be used to set,get or remove attribute from one of the following scopes:
            page
            request
            session
            application

        In JSP, page scope is the default scope.

    - page
        - it is used to store the reference of autgenerated servlet object
        
        ex: Object page = this (ref. of servlet object)

    - exception
        - it is used to define or show exception on jsp page
        - it can only be used in error pages

        <%@ page isErrorPage="true" %>  
        <html>  
        <body>  
        
            Sorry following exception occured:<%= exception %>  
        
        </body>  
        </html>  

    - application

        - In JSP, application is an implicit object of type ServletContext.

        - The instance of ServletContext is created only once by the web container when application or project is deployed on the server.

        - This object can be used to get initialization parameter from configuaration file (web.xml). It can also be used to get, set or remove attribute from the application scope.


# JSP directives

    - a JSP directive is a message that tells the web container how to translate a JSP page into the corresponding servlet.

    - syntax 

        <% @ directive_name attribute_name = "value" %>
    
    - types of JSP directives

        - 3 types

        - page directive

            - list of page directive attributes
                - import
                    - The import attribute is used to import class,interface or all the members of a package.It is similar to import keyword in java class or interface.

                    - <%@ page import="java.util.Date" %>  
                      Today is: <%= new Date() %>    

                - contentType
                    - define content type on jsp page
                    - - <%@ page contentType="text/Html" %>  

                extends
                    - The extends attribute defines the parent class that will be inherited by the generated servlet
                    - <%@ page extends="Date" %>  


                -info              
                    - This attribute simply sets the information of the JSP page which is retrieved later by using getServletInfo() method of Servlet interface.
                    - <%@ page info="composed by Sonoo Jaiswal" %> 

                -buffer
                    - The buffer attribute sets the buffer size in kilobytes to handle output generated by the JSP page.
                    - The default size of the buffer is 8Kb.

                -language
                    - The language attribute specifies the scripting language used in the JSP page. The default value is "java".

                -isELIgnored
                    - We can ignore the Expression Language (EL) in jsp by the isELIgnored attribute. By default its value is false i.e. Expression Language is enabled by default.
                    - <%@ page isELIgnored="true" %>//Now EL will be ignored  

                -isThreadSafe
                    - Servlet and JSP both are multithreaded
                    - If you want to control this behaviour of JSP page, you can use isThreadSafe attribute of page directive
                    - if the value is true then mutithreading is enabled
                    - if the value is false then mutithreading is disabled

                -autoFlush
                    - Specifies whether the buffered output is automatically flushed when the buffer is full.
                    - Default: true

                -session
                    - Specifies whether the JSP page participates in an HTTP session.
                    - Default: true
                    - <%@ page session="false" %>

                -pageEncoding
                    -  Specifies the character encoding for the JSP page.
                    - default - ISO-8859

                -errorPage
                    - The errorPage attribute is used to define the error page, if exception occurs in the current page, it will be redirected to the error page.

                    - <%@ page errorPage="myerrorpage.jsp" %>  
  

                -isErrorPage 
                    - The isErrorPage attribute is used to declare that the current page is the error page.
                    Note: The exception object can only be used in the error page.

                    <%@ page isErrorPage="true" %>  
                    The exception is: <%= exception %>  

        - include directive 
            - The include directive is used to include the contents of any resource it may be jsp file, html file or text file. 
            - The include directive includes the original content of the included resource at page translation time (the jsp page is translated only once so it will be better to include static resource).


        - taglib directive
            - The JSP taglib directive is used to define a tag library that defines many tags.
            - We use the TLD (Tag Library Descriptor) file to define the tags

            <%@ taglib uri="http://www.javatpoint.com/tags" prefix="mytag" %>  
  
            <mytag:currentDate/>  

# JSP Action Tags

    - There are many JSP action tags or elements. Each JSP action tag is used to perform some specific tasks.
    - The action tags are used to control the flow between pages and to use Java Bean

    - jsp:forward	    - forwards the request and response to another resource.
                        - <jsp:forward page="printdate.jsp" />  
  
                    
    - jsp:include       - includes another resource.
                        - The jsp include action tag includes the resource at request time so it is better for dynamic pages 
                        - <jsp:include page="printdate.jsp" />  

        
    - jsp:useBean       - creates or locates bean object.
                        

    - jsp:setProperty   sets the value of property in bean object.
    - jsp:getProperty   prints the value of property of the bean.


    - jsp:plugin        embeds another components such as applet.
    - jsp:param         sets the parameter value. It is used in forward and include mostly.


    - jsp:fallback      can be used to print the message if plugin is working. It is used in jsp:plugin.

# what is Java bean ?

    A JavaBean is a Java class that should follow the following conventions:

        - It should have a no-arg constructor.
        - It should be Serializable.
        - It should provide methods to set and get the values of the properties, known as getter and setter methods.

    -  it is a reusable software component. A bean encapsulates many objects into one object so that we can access this object from multiple places. Moreover, it provides easy maintenance.

# Attributes and Usage of jsp:useBean action tag

    - id: is used to identify the bean in the specified scope.

    - scope: represents the scope of the bean. It may be page, request, session or application. The default 
    scope is page.

    - class: instantiates the specified bean class (i.e. creates an object of the bean class) but it must have no-arg or no constructor and must not be abstract.

    - type: provides the bean a data type if the bean already exists in the scope. It is mainly used with class or beanName attribute. If you use it without class or beanName, no bean is instantiated.

    - beanName: instantiates the bean using the java.beans.Beans.instantiate() method

# Java Applet

    - Applet is a special type of program that is embedded in the webpage to generate the dynamic content. It runs inside the browser and works at client side.

    - Advantage of Applet
        - It works at client side so less response time.
        - Secured
        - It can be executed by browsers running under many plateforms, including Linux, Windows, Mac Os etc.

    - Drawback of Applet
        - Plugin is required at client browser to execute applet.
     

    Note: Jsp:plugin action tag is used in order to use applet in Jsp page

    - Hierarchy of Applet

        - Object
            |
          component
            |
          container
            |
           panel
            |
          Applet
            |
          JApplet 

    - package =  java.applet.Applet

    - Life cycle of Applet

        - Applet is initialized.
        - Applet is started.
        - Applet is painted.
        - Applet is stopped.
        - Applet is destroyed.

    - methods

        - java.applet.Applet provides 4 life cycle methods 
            
            - public void init(): is used to initialized the Applet. It is invoked only once.

            - public void start(): is invoked after the init() method or browser is maximized. It is used to start the Applet.

            - public void stop(): is used to stop the Applet. It is invoked when Applet is stop or browser is minimized.
            
            - public void destroy(): is used to destroy the Applet. It is invoked only once.

        - java.awt.Component class provides 1 life cycle method

            - public void paint(Graphics g): is used to paint the Applet. It provides Graphics class object that can be used for drawing oval, rectangle, arc etc.            

        - Who is responsible to manage the life cycle of an applet?
            Java Plug-in software.

        - There are two ways to run an applet

            By html file.
            By appletViewer tool (for testing purpose).


# Java I/O

    - Java I/O (Input and Output) is used to process the input and produce the output.

    - A stream is a sequence of data. In Java, a stream is composed of bytes. It's called a stream because it is like a stream of water that continues to flow.

    - OutputStream
        Java application uses an output stream to write data to a destination; it may be a file, an array, peripheral device or socket.

    - InputStream
        Java application uses an input stream to read data from a source; it may be a file, an array, peripheral device or socket.

    - OutputStream class is an abstract class. It is the superclass of all classes representing an output stream of bytes

    - Useful methods of OutputStream

        - public void write(int)throws IOException	
            is used to write a byte to the current output stream.

        - public void write(byte[])throws IOException	
            is used to write an array of byte to the current output stream.

        - public void flush()throws IOException	
            flushes the current output stream.

        - public void close()throws IOException	
            is used to close the current output stream.

    - InputStream class is an abstract class. It is the superclass of all classes representing an input stream of bytes.

    - Useful methods of InputStream

        - public abstract int read()throws IOException	
            reads the next byte of data from the input  stream. It returns -1 at the end of the file.

        - public int available()throws IOException	
            returns an estimate of the number of bytes that can be read from the current input stream.

        - public void close()throws IOException	
            is used to close the current input stream.

    - Heirarchical diagrams - https://www.javatpoint.com/java-io

# FileOutputStream Class

    - used for writing data to a file.
    - You can write byte-oriented as well as character-oriented data through FileOutputStream class. But, for character-oriented data, it is preferred to use FileWriter than FileOutputStream.

    - public class FileOutputStream extends OutputStream  

    - ex 1 

        FileOutputStream fout=new FileOutputStream("D:\\testout.txt");    
        fout.write(65);    
        fout.close();    

        - output

            - A

    - ex 2  

        FileOutputStream fout=new FileOutputStream("D:\\testout.txt");    
        String s="Welcome to javaTpoint.";    

        byte b[] = s.getBytes(); //converting string into byte array    

        fout.write(b);    
        fout.close();  

        - output

            - Welcome to javaTpoint.

    - methods
        -https://www.javatpoint.com/java-fileoutputstream-class

# FileInputStream Class

    - Java FileInputStream class obtains input bytes from a file
    -  It is used for reading byte-oriented data (streams of raw bytes) such as image data, audio, video etc. You can also read character-stream data. But, for reading streams of characters, it is recommended to use FileReader class.

    - public class FileInputStream extends InputStream  

    - methods

        https://www.javatpoint.com/java-fileinputstream-class

    - ex 1

        FileInputStream fin = new FileInputStream("D:\\testout.txt");    
        int i=fin.read();  
        System.out.print((char)i);    

        fin.close();    

        - the file contains = Welcome to javatpoint.

        - output
            - W

    - ex 2

        FileInputStream fin = new FileInputStream("D:\\testout.txt");    
        int i=0;    
        while((i=fin.read())!=-1){    
            System.out.print((char)i);    
        }    
        fin.close();    

        - output
            Welcome to javaTpoint

# BufferedOutputStream Class

    - Java BufferedOutputStream class is used for buffering an output stream. It internally uses buffer to store data. It adds more efficiency than to write data directly into a stream. So, it makes the performance fast.

    - OutputStream os = new BufferedOutputStream(new FileOutputStream("D:\\IO Package\\testout.txt"));  

# BufferedInputStream Class

    - Java BufferedInputStream class is used to read information from stream. It internally uses buffer mechanism to make the performance fast.

    - The important points about BufferedInputStream are:

        - When the bytes from the stream are skipped or read, the internal buffer automatically refilled from the contained input stream, many bytes at a time.
        
        - When a BufferedInputStream is created, an internal buffer array is created.

# SequenceInputStream Class

    - Java SequenceInputStream class is used to read data from multiple streams. It reads data sequentially (one by one).

# ByteArrayOutputStream Class

    - Java ByteArrayOutputStream class is used to write common data into multiple files. In this stream, the data is written into a byte array which can be written to multiple streams later.

    - The ByteArrayOutputStream holds a copy of data and forwards it to multiple streams.

    - The buffer of ByteArrayOutputStream automatically grows according to data.

# ByteArrayInputStream Class

    - The ByteArrayInputStream is composed of two words: ByteArray and InputStream. As the name suggests, it can be used to read byte array as input stream.

    - Java ByteArrayInputStream class contains an internal buffer which is used to read byte array as stream. In this stream, the data is read from a byte array.

    - The buffer of ByteArrayInputStream automatically grows according to data.

# DataOutputStream Class

    - Java DataOutputStream class allows an application to write primitive Java data types to the output stream in a machine-independent way.

    - It provides methods for writing binary representations of Java primitives

    - Java application generally uses the data output stream to write data that can later be read by a data input stream.

# DataInputStream Class

    - Java DataInputStream class allows an application to read primitive data from the input stream in a machine-independent way.

# ObjectStreamClass

    - ObjectStreamClass act as a Serialization descriptor for class. This class contains the name and serialVersionUID of the class.

# Console Class

    - The Java Console class is be used to get input from console. It provides methods to read texts and passwords.

    - If you read password using Console class, it will not be displayed to the user.

# FilePermission Class

    - Java FilePermission class contains the permission related to a directory or file. All the permissions are related with path. The path can be of two types:

    1) D:\\IO\\-: It indicates that the permission is associated with all sub directories and files recursively.

    2) D:\\IO\\*: It indicates that the permission is associated with all directory and files within this directory excluding sub directories.

# Java Writer

    - It is an abstract class for writing to character streams. The methods that a subclass must implement are write(char[], int, int), flush(), and close(). Most subclasses will override some of the methods defined here to provide higher efficiency, functionality or both.

# Java Reader

    - Java Reader is an abstract class for reading character streams. The only methods that a subclass must implement are read(char[], int, int) and close(). Most subclasses, however, will override some of the methods to provide higher efficiency, additional functionality, or both.

# Java FileWriter Class

    - Java FileWriter class is used to write character-oriented data to a file. It is character-oriented class which is used for file handling in java.

    - Unlike FileOutputStream class, you don't need to convert string into byte array because it provides method to write string directly.

    - public class FileWriter extends OutputStreamWriter  

    - methods https://www.javatpoint.com/java-filewriter-class

    - ex    

        FileWriter fw=new FileWriter("D:\\testout.txt");    
        fw.write("Welcome to javaTpoint.");    
        fw.close();  

# Java FileReader Class

    - Java FileReader class is used to read data from the file. It returns data in byte format like FileInputStream class.

    - It is character-oriented class which is used for file handling in java.

    - public class FileReader extends InputStreamReader  

    - methods  https://www.javatpoint.com/java-filereader-class

    - ex    

        FileReader fr=new FileReader("D:\\testout.txt");    
        int i;    
        while((i=fr.read())!=-1)    
        System.out.print((char)i);    
        fr.close();    

# Java CharArrayReader Class

    - The CharArrayReader is composed of two words: CharArray and Reader. The CharArrayReader class is used to read character array as a reader (stream). It inherits Reader class.

    - public class CharArrayReader extends Reader  

    - methods  https://www.javatpoint.com/java-chararrayreader-class

    - ex    

        char[] ary = { 'j', 'a', 'v', 'a', 't', 'p', 'o', 'i', 'n', 't' };  

        CharArrayReader reader = new CharArrayReader(ary);  

        int k = 0;  

        // Read until the end of a file  

        while ((k = reader.read()) != -1) {  
            char ch = (char) k;  
            System.out.print(ch + " : ");  
            System.out.println(k);  
        }  

# Java CharArrayWriter Class

    - The CharArrayWriter class can be used to write common data to multiple files. This class inherits Writer class. Its buffer automatically grows when data is written in this stream. Calling the close() method on this object has no effect.

    - methods  https://www.javatpoint.com/java-chararraywriter-class

# PrintStream Class

    - The PrintStream class provides methods to write data to another stream. The PrintStream class automatically flushes the data so there is no need to call flush() method. Moreover, its methods don't throw IOException.

# OutputStreamWriter

    - OutputStreamWriter is a class which is used to convert character stream to byte stream, the characters are encoded into byte using a specified charset.

# InputStreamReader

    - An InputStreamReader is a bridge from byte streams to character streams: It reads bytes and decodes them into characters using a specified charset. 

# PipedWriter

    - The PipedWriter class is used to write java pipe as a stream of characters. This class is used generally for writing text.

# PipedReader

    - The PipedReader class is used to read the contents of a pipe as a stream of characters. This class is used generally to read text.

# Java File Class

    - The File class is an abstract representation of file and directory pathname. A pathname can be either absolute or relative.

    - The File class have several methods for working with directories and files such as creating new directories or files, deleting and renaming directories or files, listing the contents of a directory etc.

# Java - RandomAccessFile

    - This class is used for reading and writing to random access file. A random access file behaves like a large array of bytes. There is a cursor implied to the array called file pointer, by moving the cursor we do the read write operations. If end-of-file is reached before the desired number of byte has been read than EOFException is thrown. It is a type of IOException.




# RMI (Remote Method Invocation)

    - The RMI is an API that provides a mechanism to create distributed application in java. The RMI allows an object to invoke methods on an object running in another JVM.

    - The RMI provides remote communication between the applications using two objects stub and skeleton.

    - stub

        The stub is an object, acts as a gateway for the client side. All the outgoing requests are routed through it. It resides at the client side and represents the remote object. When the caller invokes method on the stub object, it does the following tasks:

        It initiates a connection with remote Virtual Machine (JVM),
        It writes and transmits (marshals) the parameters to the remote Virtual Machine (JVM),
        It waits for the result
        It reads (unmarshals) the return value or exception, and
        It finally, returns the value to the caller.

    - skeleton

        The skeleton is an object, acts as a gateway for the server side object. All the incoming requests are routed through it. When the skeleton receives the incoming request, it does the following tasks:

        It reads the parameter for the remote method
        It invokes the method on the actual remote object, and
        It writes and transmits (marshals) the result to the caller.
        In the Java 2 SDK, an stub protocol was introduced that eliminates the need for skeletons.

    - the stub and skeleton objects are created using the rmic tool
    - The rmic tool invokes the RMI compiler and creates stub and skeleton objects.