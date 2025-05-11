# Builder pattern   

    - The Builder Pattern is a creational design pattern used to create complex objects step by step. Instead of calling multiple setters, it uses a chained method approach and ensures the object is fully initialized before use.

    - https://www.youtube.com/watch?v=KbIdk5BRn0w

    - https://www.youtube.com/watch?v=k4EkJgY9P4c

# Builder Pattern vs Setters:

    - When we can directly use the setters to set the values of attributes then why builder pattern ?

    - Pros and cons of setters

        - pros
            
            - Simple to use
            - can modify values any time

        - cons 
            
            - Object can be in an incomplete state
            - Requires multiple method calls
            - Not thread safe

    - Pros and cons of Builder pattern

        - pros
            
            - Ensures fully initialized objects
            - supports method chaining (cleaner code)
            - creates immutable objects

        - cons

            


    - There are classes without setters, called "Immutable Classes". They are used in distributed and multi-threaded programs where multiple threads can alter the states of an object. Developers use 'synchronize' to prevent this. 

    - But a more convenient approach is to use Immutable classes so that threads can't alter the states via setters.
    (If states need to be altered a new object is created! This consumes memory which is a cons of Immutable Classes
    but its worth, compared to the state-altered-havocs)
        
    - Thus for Immutable Classes, Builder Pattern has to be used instead of setters.
