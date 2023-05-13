## Day 14

## Set

    - Set is a standard template library (STL) container in C++, used in programming whenever we need to store unique elements (no duplicate values) and stored in a specifically sorted manner. The elements inside the set can be inserted or removed, but when inserted once, they cannot be modified.

    - Generally, The time complexity of operations like insertion and deletion in the set in C++ is O(logn).

    - Why set can not store duplicate values ?  

        no duplicate values can be stored in the set because each value in the set is a key, and the set doesn't support indexing. So, the elements/values(keys) are the indexes themselves, and there cannot be more than one index. Also, the values in the set need to be accessed using the keys/values only.

    - Internally the set STL in C++ is implemented by the binary search tree(Red-Black Tree).

    -   Remove elements from a set.
    
        // For single element.
        name_of_set.erase(iterator); 

        // For single element.
        name_of_set.erase(element_to_delete); 

        // For the deletion of multiple elements.
        name_of_set.erase(start_iterator, end_iterator); 
        
    - 

        Operation	Time Complexity

        insert	        O(log n)
        erase	        O(log n)
        find	        O(log n)
        size	        O(1)
        empty	        O(1)
        lower_bound	    O(log n)
        upper_bound	    O(log n)

        Note that these time complexities are for average cases. In the worst case, some operations can take O(n) time, where n is the number of elements in the set. This can happen when the self-balancing binary search tree becomes unbalanced, which can occur in rare cases.

    - Multiset is an associative container that stores elements in sorted order. It has properties similar to the set. The only difference is that Multiset can store multiple similar valued elements(duplicates allowed).

    - erase function does not give error if the value is not present in the set


## Map

    - Maps in C++ are container structures that store elements in key-value pairs. This means that for every unique key, there is a data value mapped to it, that can be easily accessed if we know the key.

    - Operation	Time Complexity

        Find	    O(log n)
        Insert	    O(log n)
        Erase	    O(log n)
        Size	    O(1)
        Clear	    O(n)

    - When Not to Use a Map in C++? 
        
        A map in C++ is a very useful data structure, especially when it comes to fast lookups based on a key, a map can provide the data element associated with a particular key very quickly.

        But, if in your code you want to iterate over all elements, or perform some operation that requires traversing over all pairs, a map may not be the best choice.