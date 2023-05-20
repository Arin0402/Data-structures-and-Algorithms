#### Ctrl+Shift+V -> to view the markdowm

    - Can read the notes from github repo (site). It has good UI

    - using const in formal parameters of function prevents the overriding of the variable in the function

        void printValue(const int value) {
            value = 42; // Error: cannot modify const object
            cout << "The value is: " << value << std::endl;
        }

    - In C++, insert and emplace are both member functions of the standard container classes that allow you to add elements to a container. However, there are some differences between the two functions in terms of their behavior and performance.

    insert takes an object of the container's value type as an argument, creates a copy of the object, and inserts the copy into the container. If the object already exists in the container, the insert function has no effect.

    On the other hand, emplace constructs the object in-place within the container using the arguments passed to the function. This means that emplace avoids the overhead of creating a temporary object and copying it into the container. If the object already exists in the container, emplace has no effect.

    One advantage of emplace is that it can be more efficient than insert in certain situations. Since emplace constructs the object in-place, it can avoid the overhead of creating a temporary object and copying it into the container. This can be particularly beneficial for containers of complex objects that are expensive to copy.


        std::map<int, std::string> myMap;

        // Using insert
        myMap.insert(std::make_pair(1, "one"));

        // Using emplace
        myMap.emplace(2, "two");

        // Accessing elements in the map
        std::cout << "myMap[1] = " << myMap[1] << std::endl;
        std::cout << "myMap[2] = " << myMap[2] << std::endl;

    Note that when we use insert, we have to use the std::make_pair function to create a pair of key-value elements to insert into the map. On the other hand, when we use emplace, we can pass the key-value elements directly to the function, and the elements will be constructed in-place within the map.

    In general, if you have a container of complex objects that are expensive to copy, you should prefer emplace over insert to avoid the overhead of creating temporary objects. However, if you are inserting simple objects or objects that are cheap to copy, insert may be a better choice as it can be more concise and easier to read.

    - Also checkout Java folder.