# if given array in arr[100][112] and base address of 1200 so what will be the address of arr[80][20] ?

    - If nothing is given,then we would assume it is stored in row major( means rows are filled first while storing elements)

    1. Calculate the number of elements before arr[80][20]:

        Full rows before the 80th row: 
            80×112=8960 elements

        Elements before arr[80][20] in the 80th row: 
            20 elements

        Total number of elements before arr[80][20]: 
            8960+20=8980 elements

    2. Calculate the offset in bytes:

        8980 elements * 4 bytes/element = 35920 bytes ( 2 bytes or 4 bytes depends upon the language)

    3. Calculate the base address of arr[80][20]:

        1200+35920 = 37120

    So, the base address of arr[80][20] is 37120.        

# The Java Virtual Machine (JVM) throws an ArrayIndexOutOfBoundsException if length of the array in negative, equal to the array size or greater than the array size while traversing the array.

# Jagged Array in Java

    - If we are creating odd number of columns in a 2D array, it is known as a jagged array. In other words, it is an array of arrays with different number of columns.
        
    - int arr[][] = new int[3][];  
        arr[0] = new int[3];  
        arr[1] = new int[4];  
        arr[2] = new int[2];  

# Copying a Java Array

    - We can copy an array to another by the arraycopy() method of System class.

    - public static void arraycopy(  
        Object src, int srcPos,Object dest, int destPos, int length  
      )  
    
    - char[] copyFrom = { 'd', 'e', 'c', 'a', 'f', 'f', 'e', 'i', 'n', 'a', 't', 'e', 'd' };  
        
        char[] copyTo = new char[7];  
        
        System.arraycopy(copyFrom, 2, copyTo, 0, 7);  

# IMP Cloning an Array in Java

    - Since, Java array implements the Cloneable interface, we can create the clone of the Java array. If we create the clone of a single-dimensional array, it creates the deep copy of the Java array. It means, it will copy the actual value. But, if we create the clone of a multidimensional array, it creates the shallow copy of the Java array which means it copies the references.

    - int carr[]=arr.clone();  

    - When you use the clone() method on a 1D array, Java performs a shallow copy, which in the case of a 1D array is effectively the same as a deep copy

# Monitor is used for concurrency control in java

# Sunstring in java
    
    - substring(int begIndex, int endIndex);
    - the begin index, inclusive.
    - the end index, exclusive.

# Generics are used to parameterize teh collections in order to perform static type checking

# CLS stands for Common Language Specification and it is a subset of CTS. It defines a set of rules and restrictions that every language must follow which runs under the . NET framework. 

# SQLDataReader is faster and consumes lesser memory

# A ring refers to a record chain, the last of which refers to the first record in the chain is callod pointer

# int (*ptr)[10] 
    - ptr is an pointer to an array of 10 integers

# Embedded pointer provides an secondary access path

# Symantec's visual cafe is not a part of Java IDE

# Java garbage collector is a low priority process

# the output of

    75.22 + "5.2" is "75.2252" 

    - when one operand is float and other is string then + acts as concatenation    

# carraige return = \r

# JAR file = Java Archive file

# first ever OOPs language = Simula 67

# comments  by javadoc tool 
    start with /**  
    end with */

# Combo box is a drop down list

# the location of the form on desktop (OOP in Visual Basic) during execution is determined by the form layout window

# first robot with AI to fly in space

# (in book) PC 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 

# a friend function can be declared anywhere(private/public) in the class

    - java does not support friend function

# by polymorphism of a system, we mean it should accept generic commands and interpret appropriately