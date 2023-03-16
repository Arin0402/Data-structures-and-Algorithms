## Datatypes

    1 Tuples are immutable. Real life exmaple - Tuple to store the latitude and longitude of your home,

    2 frozenset are immutable
        x = frozenset({"apple", "banana", "cherry"})

## Difference between tuple and frozen set

    tuples are immutable lists, frozensets are immutable sets.

    tuples are indeed an ordered collection of objects, but they can contain duplicates and unhashable objects, and have slice functionality

    frozensets aren't indexed, but you have the functionality of sets - O(1) element lookups, and functionality such as unions and intersections. They also can't contain duplicates, like their mutable counterparts.

## Bytes and Bytes array in python

    - The bytes data type is used to represent a group of byte number.
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
