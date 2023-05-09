#### Ctrl+Shift+V -> to view the markdowm


- using const in formal parameters of function prevents the overriding of the variable in the function

    void printValue(const int value) {
        value = 42; // Error: cannot modify const object
        cout << "The value is: " << value << std::endl;
    }