# Singleton pattern

    - A Singleton Class ensures that only one instance of the class is created and provides a global access point to it.

    ✅ Key Benefits:

        ✔ Saves memory by reusing the same object
        ✔ Prevents multiple instances, avoiding conflicts
        ✔ Used in logging, database connections, caching, etc.

    https://www.youtube.com/watch?v=SqDbZOjW1uM

    Methods of creating singleton class

    1. Eager initialization

        - Obeject is static and is created when the class itself is loaded
        - dis
            - If the object is not required, then also it is craeted at the first place so it is a wastage of memory

    2. Lazy initialization

        - We check if the object has been formed or not ( if obj == null)
        - if the object is null, then only we create the object
        - dis
            - If two threads come simlutaneously, then they would pass the if condition and two objects would get created

    3. Synchronized method              

        - We use the synchornized keyword, but the problem is that it will slow down the process as one thread would accquire the lock and other woud wait so time consuming

    4. Double check locking             

        - we will check twice if the object is null or not 
        - We use volatile keyqword also. (IMP) (https://youtu.be/SqDbZOjW1uM?t=661)
        - With the help of volatile keyword, memory is directly updated instead of updating cache. All read/write operations take place from memory only

    5. Bill paugh's solution

        - We write the initialization part of the object inside the nestesd static class.
        - The property of nested static class is that it gets loaded into the memory only when it is being referred. So the object would be created only when we refer to this nested static class
        - Details in video

    6. Using enum (works for Java 1.5 + )
        
        - It would create a single instnce only by default
        - https://www.youtube.com/watch?v=YOi5i-93lgo (explained more clearly)