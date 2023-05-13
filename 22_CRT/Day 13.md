## Day 13

## Vector

    - vector is a class template in C++. It is defined in the <vector> header file and is part of the Standard Template Library (STL). It is a conatiner in STL.
    - vector is implemented as a dynamic array, which means that it can automatically grow or shrink in size as elements are added or removed from the container at the run time.
    
    - When vector allocates memory to the new element then it allocates memory equal to the current size of the vector.
    - This is done to allocate memory to a new element coming after this current element in a faster way.
    - finding new memory every time for a new element is costly operation so that's why it automatically reserves some extra space.
    - If the vector is unable to reserve the extra space equal to the current size of the vector, then it frees up the current meemory occupied and finds the new block of memory with size equal to current size + extra space.

    - so the size of the vector is the total number of elements in it and the capacity of the vector is the total memory occupied by it.

    - 1 2 3 4 5 _ _ _ 

        - here size is 5
               capacity is 8

    - But this is the wastage of memory, so to release the unused memory, shrink_to_fit() function is called. By doing this, the size and the capacity of the vector becomes same.

    - we can also use this function when we remove elements from the vector

## iterators

    - In C++, an iterator is an object that provides a way to access the elements of a container (such as a vector, list, or map) sequentially, without exposing the underlying implementation details of the container. Iterators are essentially pointers to the elements of the container, with additional functionality to move to the next or previous element and to compare iterators.

    - Types of iterator

        - iterator -> iterates from starting to end

            vector<int>::iterator itr;

            for( itr = v.begin(); itr != v.end(); itr++)

        - reverse iterator -> iterates in the reverse direction

            vector<int>::reverse_iterator j;
    
            for(j = v1.rbegin(); j != v1.rend(); j++)

            - Note that j will be incremented here not decremented

        - constant iterator -> iterates from starting to end and we cannot modify the value at the address

            vector<int>::const_iterator k;
    
            for(k = v1.cbegin(); k != v1.cend(); k++)

                //*k += 2;  error
                cout<<*k<<" ";

        - constant reverse iterator -> iterates in the reverse direction and we cannot modify the value at the address

            vector<int>::const_reverse_iterator l;
    
            for( l = v1.crbegin(); l != v1.crend(); l++)

## Demonstartion

### code 1

    #include<iostream>
    #include<vector>
    using namespace std;
    int main()
    {
        vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        
        cout<<v1.size()<<endl;
        cout<<v1.capacity()<<endl;
        
        v1.shrink_to_fit();
        
        cout<<v1.size()<<endl;
        cout<<v1.capacity()<<endl;
        
        vector<int>::iterator i;
        
        for(i  = v1.begin(); i != v1.end(); i++)
        {
            *i=*i+2;
            cout<<*i<<" ";
        }
        cout<<endl;

        vector<int>::reverse_iterator j;
        
        for(j = v1.rbegin(); j != v1.rend(); j++)
        {
            *j -= 2;
            cout<<*j<<" ";
        }
        cout<<endl;

        vector<int>::const_iterator k;
        
        for(k = v1.cbegin(); k != v1.cend(); k++)
        {
            //*k += 2;  error
            cout<<*k<<" ";
        }
        cout<<endl;

        vector<int>::const_reverse_iterator l;
        
        for( l = v1.crbegin(); l != v1.crend(); l++)
        {
            //*l += 2; error
            cout<<*l<<" ";
        }
        cout<<endl;

        for(auto a = v1.crbegin(); a != v1.crend(); a++){
            // *a += 10;  error
            cout<<*a<<"  ";
        }

    }


### code 2

    #include<iostream>
    #include<vector>
    #include<array>
    using namespace std;
    
    // To print the vector
    void output(vector<int> &r)
    {
        for(int a:r)        //for each loop
            cout<<a<<" ";
        cout<<endl;
    }

    int main()
    {
        vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        
        auto a = v1.begin()+2;

        // insert an element at third position from start    
        v1.insert(a,100);
        output(v1);
    
        // remove an element at third position from start
        v1.erase(a);
        output(v1);

        // set the size of the vector to 0. elements will be still present but can not be accessed
        v1.clear();
        
        cout<<v1.size()<<endl;
        cout<<v1.capacity()<<endl;
        

        // compare two vectors
        vector<int> v2={10,20,30,40,50};
        vector<int> v3={100,200,300,400,500};


        // overloading of == has been done here
        if(v2 == v3)
            cout<<"v2 == v3";
        else
            cout<<"v2 != v3";
        cout<<endl;
        
        
        // swap two vectors. Temporary object of vector is created then it is swapped.
        v2.swap(v3);

        output(v2);     //100 200 300 400 500
        output(v3);     //10 20 30 40 50


        // the maximum number of elements that the current vector can hold based on the memory available in RAM.
        cout<<v1.max_size();
        

        // creating array using array class template
        array<int,10> a1;       //static array
    }