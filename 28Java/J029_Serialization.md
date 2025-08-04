### What is serialization ?

- Serialization is the conversion of java object into a static stream(sequence) of bytes, which we can then save to a database or transfer over a network.
- Classes that are eligible for serialization need to implement a special marker interface, Serializable. The JVM allows special priviliges to the class which implements the serializable interface.
- Byte stream is platform-independent. This means that once you have a stream of bytes you can convert it into an object and run it on any kind of environment.
- A class to be serialized successfully, 2 conditions must be met

1. The class must implement the java.io.serializable interface.
2. All of the fields in the class must be serializable. If a field is not serializable, it must be marked transient,
3. Static fields belong to a class(as opposed to an object) and because of this reason are not serialized.

- Way to convert an object into a stream of Bytes - "ObjectOutputStream" which consists of a a method "writeObject"
- Way to convert stream of bytes into an object - "ObjectInputStream" which consists of a method readObject();

```java
FileOutputStream fileOut = new FileOutputStream("/tmp/employee.ser");
ObjectOutputStream out = new ObjectOutputStream(fileOut);
out.writeObject(e);
out.close();
fileOut.close();
```

```java
public class Employee implements Serializable{
    private static final long serialVersionUID = 1L; // this is required while implementing serializable
    private int id;
    private String name;


    //getters and setters
}

public class Main{
    public static void main(String[] args) throws FileNotFoundException{
        Employee e = new Employee();
        e.setId(1);
        e.setName("Akshit");

        //serialization example
        FileOutputStream fileOut = new FileOutputStream("D:\\tmp\\employee.ser");
        ObjectOutputStream out = new ObjectOutputStream(fileOut);
        out.writeObject(e);
        out.close();
        fileOut.close();
    }
}
```

### What is Deserialization ?

Deserialization is precisely the opposite of serialization. With deserialization, you start with a byte stream and re - create the object you previously serialized in its original state. However, you must have the definition of the object to successfully re-create it.

FileInputStream fileIn = new FileInputStream("/tmp/employee.ser");
ObjectInputStream in = new ObjectInputStream(fileIn);
e = (Employee) in.readObject();
in.close();
fileIn.close();

### What is searial version UID ?

The JVM associates a version number with each serializable class, We use the serialVersionUID attribute to remember versions of a serializable class to verify that a loaded class and the serialized object are compatible.
Most IDEs can generate this number automatically, and it's based on the class name, attributes, and associated acess modifiers. Any changes result in a different number and can cause an InvalidClassException.
If a serializable class doesn't declare a serialVersionUID, the JVM will generate one automatically at run-time. However it's highly recommended that each class declares its serialVersionUID as the generated one is compiler dependent and thus may result in unexpected InvalidClassExceptions.

### How does java serialization work ?

Java serialization uses reflection to scrape all necessary data from the object's fields, including private and final fields. If a field contains an object, that object is serialized recursively. Even though you might have getters and setters, these functions are not used when serializing an object in java.

### when we create a field like

private transient String name;

this type of field is ignored by jvm while serializing the object.
**Similarly static fileds, since are not part of the objects are ignored by JVM while serializing**

### What is Externalization ?

Externalization in java is used whenever you need to customize the serialization mechanism,

- In serialization, the java virtual machine is totally responsible for the process of writing and reading objects. This is useful in most cases as the programmers do not have to care about the underlying details of the serialization process. However the default serialization does not protect sensitive information such as passwords and credentials, or what if the programmers want to secure some information during the serialization process ?
- Thus externalization comes to give the programmers fulll control in reading and writing objects during serailization. JVM has no control over it. THe complete serialization control goes to the application,.
- Based on our requirements, we can serialize either the whole data field or a piece of the data field using the externalizable interface which can help to improve the performance of the application,.
- Externalizable interface internally extends Serializable interface.

### How does it work?

- In the serialization process, JVM first checks for externalizable interface. If objects support Externalizable interface, JVM serializes objects using writeExternal() method.
- If objects do not support Externalizable but implement Serializable, objects are stored using ObjectOutputStream.
- For Serializable objects, JVM serializes the only instance variables that are not declared with the transient keyword.
- For Externalizable objects, we have full control over what pieces of data have to serialize and what to not serialize.
- Order of reads must be the same as order of writes.

### Difference b/w serialization and externalization

- Serializable is a marker interface i.e it does not contain any method.
- The externalizable interface is not a marker interface and thus it defines 2 methods writeExternal() and readExternal()

- Serializable interface passes the responsibility of serailization to the JVM and the programmer has no control over serialization, and it is a default algorithm.
- The externalizable interface provides all serialization responsibilities to a programmer and hence JVM has no control over serialization.

- Default serialization does not require any no-aarg constructor.
- A public no-arg constructor is required while using an Externalizable interface.

### What is a Java deserialize vulnerability

A java deserialize vulnerability is a security vulnerability that occurs when a malicious user tries to insert a modified serialized object into the system in order to compromise the system or its data.
A serialized object in java is a byte array with state information. If you look at a sorted serialized object with a hex-editor, you can enclose and manipulate the information quickly.
Thus if an application accepts serialized objects, it is relatively easy to tamper with the values. By altering the serialized objects, we can create invalid objects, alter the data's integrity, or worse.

### How to prevent a java deserialze vulnerability ?

- The best way to prevent a java deserialize vulnerability is to prevent java serialization overall. If your application does not use accept serialized objects, it can't hurt you.
  However if you do need to implement the 'serializable' interface due to inheritance, you can override the readObject() as seen below, to prevent actual deserialization.

private final void readObject(ObjectInputStream in) throws java.io.IOException {
throw new java.io.IOException("Deserialized not allowed");
}

- Do not accept serialized objects from untrusted sources
- Keep your .ser files at secure loaction, keep it restricted and only authorized persons can access that file.
- Don't store passwords like sensitive info as serialization is prone to vulnerabilities.
