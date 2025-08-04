## what will happen if you don't override equals and hashcode method

Here's what might happen if you don't override the equals() and hashCode() methods:

Incorrect Equality Comparison: The default implementation of equals() compares object references, not the content of the objects. So, two different instances with the same content won't be considered equal unless you override the equals() method to provide custom comparison logic.

Loss of Data in Hash-Based Collections: In hash-based collections like HashSet and HashMap, the hashCode() method determines the bucket where an object should be stored. If you don't override hashCode(), the default implementation based on the object's memory address will be used. As a result, even instances with the same content might end up in different buckets, leading to inefficiency and incorrect behavior.
