### Day 3

    1. for pattern problems, first write all the ranges of the triangles, then write the code

        - most used initializers

            - j = 2*i - 1 -> for odd number
            - j = 2*(n - i) - 1 -> for odd number in reverse order
            - j = 2*(i-1) - 1
            - j = i - 1 -> for skipping one line

    2. Print the pattern

        1
        2 6
        3 7 10
        4 8 11 13
        5 9 12 14 15

        #include<stdio.h>
        #include<math.h>

        int main()
        {
            int i,j,n,a;

            printf( "Enter no of rows: " );
            scanf("%d",&n);

            for(i = 1 ; i <= n; i++)
            {
                a=i;

                for(j = 1; j <= i; j++)
                {
                    printf("%d ",a);
                    a = a+n-j;
                }

                printf("\n");
            }
            return 0;
        }

    3. Print the pattern


        1               1
        1 2           2 1
        1 2 3       3 2 1
        1 2 3 4   4 3 2 1
        1 2 3 4 5 4 3 2 1

        #include<stdio.h>
        #include<math.h>

        int main()
        {
            int i,j,n,k,l;

            printf( "Enter no of rows: " );
            scanf("%d",&n);

            for(i=1; i<=n; i++)
            {
                // printing the first triangle
                for(j = 1; j <= i; j++)
                    printf("%d ",j);

                // printing the space triangle
                for(k = 1; k <= (n-i)*2-1; k++)
                    printf("%c ",32);


                // printing the last triangle
                for(l = i; l >= 1; l--)
                {
                    if(l==n)
                        continue;
                    printf("%d ",l);
                }

                printf("\n");
            }
            return 0;
        }

    4. Print the pattern

          *
         * *
        *****
       *     *
      *       *

        #include<stdio.h>
        #include<math.h>

        int main()
        {
            int i,j,n,k,l;

            printf(" Enter no of rows: ");
            scanf("%d",&n);

            for( i = 1; i <= n; i++)
            {
                // print the space triangle
                for(k = 1;k <= n-i; k++)
                    printf("%c",32);

                // printing the A
                for( j = 1; j <= i*2-1 ; j++)

                    // if it is first or last element or the row is middle, then print *
                    if(j==1 || j==i*2-1 || i==(n+1)/2)
                        printf("*");
                    else
                        printf("%c",32);


                printf("\n");
            }
            return 0;
        }

    5. for loop

        - for( ; ; ){
                print("Hello")
          }
        - Output -> Infinite times hello
        - the empty condition is always true

    6. Fibonacci starts with 1

        - Fibonacci series -> sum of previous 2 elements
        - Lucas series -> sum of previous 3 elements

    7. Jump statements

        - break -> used to terminate loop or switch

            if(i == 5)
                break;

            - this will give error

        - continue -> used to skip all the remaining statements and jump to the next step of the loop

        - return -> It is used to transfer control from called function to the calling function
