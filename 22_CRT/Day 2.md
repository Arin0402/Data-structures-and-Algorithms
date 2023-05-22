### Day 2

    1. Switch case is faster than the if else statement

        - if else statement compares with each condition at the run time whereas switch case stores the condition
            using hashing at the compile time so that checking and looking for the condition is faster at the run time

    2. Print the number of days in a month using only 3 printf statements. The prints stateents should be inside the switch case

        switch(month){

            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                printf("31 days");
                break;
            case 2:
                printf("28/29 days");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                printf("30 days");
                break;
            default:
                printf("invalid input");

        }

    3. WAP to check if a year is leap year or not

        - if the year is century year, then for it to be a leap year, it should be divisible by 400
        - else if it is not a century year, then for it to be a leap year, it should be divisible by 4
        - year which is divisible by 400 is automatically divisible by 4

        if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0){
            leap year
        }
        else{
            not a leap year
        }

    4. Conditional operator ( ? :) -> Ternary operator

    5. Logical operators

        - !
        - &&
        - ||

        - these are written in the order of precedence

        - printf("%d", !5)
        - output -> 0

    6. short circuting

        a = 1, b = 0, c = 1

        if(a-- || b++ && c++) printf("hello");
        else printf("bye");

        print(" %d%d%d ", a, b, c);

        output - > Hello 0 0 1

        - the first condition a-- would be check, it is TRUE so no further condition would be checked
        - this is called short circuting

    7. Bit wise operators

        - &     |       ^       <<      >>      ~

    8. Right shift of negative integer ( -5 >> 1)

        - whenever the right shift of negative integer is done ( -5 >> 1)
        - then in the memory

            - -ve 5 is stored in the 2's complement form of +ve 5
            - right shift by 1 is done
            - the 32 bit is replaced by 1 not 0
            - the 32 bit is the sign bit and it is always replaced by the previous sign bit

    9. Negation (~) -> Bitwise not

        - printf( ~5 )
        - output -> -6
        - all the 32 bits are flipped

    10.
        float a = 0.7

        if(a == 0.7) print(True)
        else print(Flase)

        - output -> False
        - 0.7 is of double type which takes 8 bytes
        - flaot takes 4 bytes
        - so when we try to store the double in float, then overflow occurs and the value is not 0.7.
        - It is like 0.69872


        float a = 0.7f

        if(a == 0.7f) print(True)
        else print(Flase)

        - output -> True
        - this is the correct way to store the float values

    11. Types of loops

        - Entry control loops

            - for loop
            - while loop

        - Exit control loop

            - do while loop


    12. While loop

        - Syntax
            - Initialization
            - condition
            - statement
            - inc/dec
