## Datatypes

    1 Tuples are immutable. Real life exmaple - Tuple to store the latitude and longitude of your home,

    2 frozenset are immutable
        x = frozenset({"apple", "banana", "cherry"})

## Difference between tuple and frozen set

    tuples are immutable lists, frozensets are immutable sets.

    tuples are indeed an ordered collection of objects, but they can contain duplicates and unhashable objects, and have slice functionality

    frozensets aren't indexed, but you have the functionality of sets - O(1) element lookups, and functionality such as unions and intersections. They also can't contain duplicates, like their mutable counterparts.

## Bytes and Bytes array in python

    - The bytes data type in Python is used to represent a sequence of bytes. It is a built-in data type that is  often used to work with binary data, such as reading and writing binary files, encoding and decoding data, and dealing with network protocols
    - Bytes is just like an array which can hold multiple values.
    - Bytes can store the number in between 0 to 255 (included).
    - Bytes can not hold negative numbers
    - ex  a = [10, 20, 30, 40]
          b = Bytes(a)

## Difference between bytes and bytes array

    - bytes array is same as bytes
    - the only difference is that you can modify the elements in bytes array but can't in bytes.

## Command line arguments in python

    <!-- https://www.geeksforgeeks.org/command-line-arguments-in-python/ -->

    import sys

    # total arguments
    n = len(sys.argv)
    print("Total arguments passed:", n)

    # Arguments passed
    print("\nName of Python script:", sys.argv[0])

    print("\nArguments passed:", end = " ")
    for i in range(1, n):
        print(sys.argv[i], end = " ")

    # Addition of numbers
    Sum = 0
    # Using argparse module
    for i in range(1, n):
        Sum += int(sys.argv[i])

    print("\n\nResult:", Sum)

## Tuple and list

    tuples are stored in a single memory block therefore they don’t require extra space for new objects whereas the lists are allocated in two blocks, first the fixed one with all the Python object information and second a variable sized block for the data.


- arr[start:stop]         # items start through stop-1
- ord(): This function is used to convert a character to an integer.
- To convert an integer to a character in Python, we can use the chr() method

- c++ vs python

- Python is a popular programming language. It was created by Guido van Rossum, and released in 1991.

    Python can be used on a server to create web applications.
    Python can be used alongside software to create workflows.
    Python can connect to database systems. It can also read and modify files.  
    Python can be used to handle big data and perform complex mathematics.


- To change the value of a global variable inside a function, refer to the variable by using the global keyword:

    x = "awesome"

    def myfunc():
        global x
        x = "fantastic"

    myfunc()

    print("Python is " + x) -> Python is fantastic


- Python does not have a character data type, a single character is simply a string with a length of 1.

- Check if "free" is present in the following text:

    txt = "The best things in life are free!"
    print("free" in txt)


- The strip() method removes any whitespace from the beginning or the end:

    a = " Hello, World! "
    print(a.strip()) # returns "Hello, World!"

- The replace() method replaces a string with another string:

    a = "Hello, World!"
    print(a.replace("H", "J"))

- Use the format() method to insert numbers into strings:

    age = 36
    txt = "My name is John, and I am {}"
    print(txt.format(age))

- The escape character allows you to use double quotes when you normally would not be allowed:

    txt = "We are the so-called \"Vikings\" from the north."

- In fact, there are not many values that evaluate to False, except empty values, such as (), [], {}, "", the number 0, and the value None. And of course the value False evaluates to False.

- To insert a new list item, without replacing any of the existing values, we can use the insert() method.

    The insert() method inserts an item at the specified index:

    Example
    Insert "watermelon" as the third item:

    thislist = ["apple", "banana", "cherry"]
    thislist.insert(2, "watermelon")
    print(thislist)

- To add an item to the end of the list, use the append() method:

    Using the append() method to append an item:

    thislist = ["apple", "banana", "cherry"]
    thislist.append("orange")
    print(thislist)

- Sort the list based on how close the number is to 50:

    def myfunc(n):
    return abs(n - 50)

    thislist = [100, 50, 65, 82, 23]
    thislist.sort(key = myfunc)
    print(thislist)

- You cannot copy a list simply by typing list2 = list1, because: list2 will only be a reference to list1, and changes made in list1 will automatically also be made in list2.

    There are ways to make a copy, one way is to use the built-in List method copy().

    Make a copy of a list with the copy() method:

    thislist = ["apple", "banana", "cherry"]
    mylist = thislist.copy()
    print(mylist)

- Note: When creating a tuple with only one item, remember to include a comma after the item, otherwise it will not be identified as a tuple.

- . You are allowed to add tuples to tuples, so if you want to add one item, (or many), create a new tuple with the item(s), and add it to the existing tuple:

- To add items from another set into the current set, use the update() method.

    thisset = {"apple", "banana", "cherry"}
    tropical = {"pineapple", "mango", "papaya"}

    thisset.update(tropical)

- To remove an item in a set, use the remove(), or the discard() method.

    Note: If the item to remove does not exist, remove() will raise an error.

    Note: If the item to remove does not exist, discard() will NOT raise an error.

- Loop through both keys and values, by using the items() method:

    for x, y in thisdict.items():
      print(x, y)

- If the number of arguments is unknown, add a * before the parameter name:

    def my_function(*kids):
    print("The youngest child is " + kids[2])

    my_function("Emil", "Tobias", "Linus")

- If you do not know how many keyword arguments that will be passed into your function, add two asterisk: ** before the parameter name in the function definition.

This way the function will receive a dictionary of arguments, and can access the items accordingly:

Example
If the number of keyword arguments is unknown, add a double ** before the parameter name:

def my_function(**kid):
  print("His last name is " + kid["lname"])

my_function(fname = "Tobias", lname = "Refsnes")

- A lambda function is a small anonymous function.

- A lambda function can take any number of arguments, but can only have one expression


- Why Use Lambda Functions?
    The power of lambda is better shown when you use them as an anonymous function inside another function.

    Say you have a function definition that takes one argument, and that argument will be multiplied with an unknown number:

    def myfunc(n):
        return lambda a : a * n

    mydoubler = myfunc(2)

    print(mydoubler(11))

- class MyClass:
  x = 5

    obj = MyClass();
    print(obj.x)

- class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def myfunc(self):
        print("Hello my name is " + self.name)

  p1 = Person("John", 36)
  p1.myfunc()

- The self parameter is a reference to the current instance of the class, and is used to access variables that belong to the class.

- It does not have to be named self , you can call it whatever you like, but it has to be the first parameter of any function in the class:

- The try block lets you test a block of code for errors.

-The except block lets you handle the error.

-The else block lets you execute code when there is no error.

-The finally block lets you execute code, regardless of the result of the try- and except blocks

- The raise keyword is used to raise an exception.

    raise Exception("Sorry, no numbers below zero")

- # Using str.format()
    value = 3.14159265
    formatted_value = "{:.2f}".format(value)
    print(formatted_value)  # Output: 3.14

-   value = 3.14159265
    rounded_value = round(value, 2)
    print(rounded_value)  # Output: 3.14


- for cpp

        std::cout << std::fixed << std::setprecision(2) << value << std::endl; // Output: 3.14


