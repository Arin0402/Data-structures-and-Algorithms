### In how many ways can we create string object in java ?

```java
//1) below statement 2 objects are created
//1 - object - > because of new -> on heap
//2 - object - > because of literal "hello" -> inside string constant pool area
String s = new String("hello");


//1) now in  this case
// no object will be created it is refering to the hello created in string constant pool
String s2 = "hello";




```

### Why strings are immutable in java ?

Immutable simply means unmodifiable or unchangeable

- String pool is possible only because string is immutable in java. This way java run time saves a lot of heap space because different string variables can refer to the same string variable in the pool.
- Since string is immutasble, it is safe for multithreading. A single string instance can be shared across different threads. This avoids the use of synchronization for thread safety.
- Since string is immutable, its hashcode is cached at the time of creation and it does not need to be calculated again. This makes it a great candidate for the key in a a map and its processing is faster than other hashmap key objects. This is why string is most widely used as hashmap keys.

## While creating our own custom immutable objects we have read the conditions previously like make the class final, make no setters, make all fields private and final and set them through constructor but what would happen in cases like this ?

```java
    class Immutable{
        private final List<String> arr;

        public Immutable(List<String> arr){
            this.arr = arr;
        }

        public void getArr(){
            return arr;
            //return  new ArrayList<>(arr);
            //or
            //returnCollections.unmodifiablelist(arr);
        }
    }


    public class Main{
        public static void main(String[] args){
            Immutable imm = new Immutable(Arrays.asList("akshit", "goyal"));
            imm.getArr().add("Kumar"); //this will add element to the list even though we have made it immutable

            //to tackle this we need to return the copy of the arraylist instead of the actual array
            //we can return something like this
            // new ArrayList<>(arr);
            // //or
            // Collections.unmodifiablelist(arr);




            //Same thing can happen with objects as well, in that case as well we need to return the copy of the objects instead of actual objects because actual objects has setter methods attached to it and someone might modify it using those setter methods.
        }
    }
```

### Which one is good to store passwords in java String or char[] & why ?

Since strings are immutable in java if you store the password as plain text it will be available in memory until the garbage collector clears it and also string literal is stored in string pool for reusability there is a pretty high chance that it will remain in memory for long duration

if garbage collector was not able to destroy literal from string constant pool it might only get destroyed when the jvm restarts, this may lead to high security threats.

Anyone who has access to memory dump can find the password in clear text and that's another reason you should always use an encrypted password than plain text.

Since strings are immutable there are no way contents of strings can be changed because any change will produce new string, while if you use char[] you can still set all his elements as blank or zero. So storing the passowd in character array clearly mitigates security risk of stealing passwords.

with string there is always a risk of printing plain text in log file or console but if use array you won't print contents of array instead its memory location get printed though not a real reason but still make sense.

###

    public class StringDemo {
     		public static void main(String[] args) {
    			String word1 = "Willow", word2 = "ow";

    	        System.out.println(word1 == "Willow");
    	        System.out.println(word1 == ("Will"+"ow"));
    	        System.out.println(word1 == ("Will"+word2));
    	    }
    	}

    	//output == true true false;
    	When two literal strings are used as operands for the + operator, the resultant string will be checked in the String Literal Pool for its existence.
    	When using a non-literal as one or many operands for the + operator, a new string is created, without checking the String Literal Pool.

### Explain java string pool

A collection of string in java's heap memory is referred as java string pool. In case you try to create a new string object, JVM first checks for the presence of the object in the pool. If available the same object reference is shared with the variable, else a new object is created.

### Exception

an exception in java is an unexpected event that can disrupt the normal flow of the program.

### What happens when main() is not declared static ?

When the main() method is not declared static the program may be compiled successfully but ends up with a serious ambiguity and throws a runtime error that reads "NoSuchMethodError"
