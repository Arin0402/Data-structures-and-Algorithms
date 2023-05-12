## Day 13

## Vector

    - vector is a class template in C++. It is defined in the <vector> header file and is part of the Standard Template Library (STL).
    - vector is implemented as a dynamic array, which means that it can automatically grow or shrink in size as elements are added or removed from the container at the run time.
    
    - When vector allocates memory to the new element then it reserves some extra space larger than the required space.
    - This is done to allocate memory to a new element in a faster way.
    - finding new memory every time for a new element is costly operation so that's why it automatically reserves some extra space.

    - so the size of the vector is the total number of elements in it and the capacity of the vector is the total memory occupied by it.

    - 1 2 3 4 5 _ _ _ 

        - here size is 5
               capacity is 8

    - But this is the wastage of memory, so to release the unused memory, shrink_to_fit() function is called. By doing this, the size and the capacity of the vector becomes same.

    - we can also can this function when we remove elements from the vector

