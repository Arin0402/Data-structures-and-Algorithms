### Day 1

    2. What is compiler

        - converts source code into machine code
        - converts source code into executable file which can be run by the OS

    3. Main function is a special user defined function
        - user can not change the name of it, but can define the working of it

    5. space print using printf

        - printf("% 4d", 10)
        - output -> _ _ 1 0 (actual output -> __10 , two spaces at start and two space for the number)

        - printf("% -4d", 10)
        - output -> 1 0 _ _ (actual output -> 10__)

        - can also be written as
        - printf("% *d", 4, 10)  // 4 goes in place of *
        - output -> _ _  1 0

    6. Calculate the sum of two numbers without using any operator

        - a = 5;
        - b = 6;
        - sum = printf("%*c %*c", a, ' ', b, ' ' )
        - output -> 11
        - It would look someting like this _ _ _ _ ' '_ _ _ _ _ ' '

    7. \n , \r is called escape sequence

        - \n -> go to the starting of next line
        - \r -> go to starting of the current line

    8. Swap two numbers

        - a = a + b
          b = a - b
          a = a - b

        - a = a * b
          b = a / b
          a = a / b

        - a = a ^ b
          b = a ^ b
          a = a ^ b

    10. characters and ascii range
            
        A - Z = 65 - 90
        a - z = 97 - 122
        '0' - '9' = 48 - 57
        space = 32

        - Difference between A and a is 32
        - A + 32 = a
        - a - 32 = A
