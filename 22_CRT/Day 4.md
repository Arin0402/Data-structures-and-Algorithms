### Day 4

    1. Print the pattern

        5 5 5 5 5 5 5 5 5
        5 4 4 4 4 4 4 4 5
        5 4 3 3 3 3 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 2 1 2 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 3 3 3 3 4 5
        5 4 4 4 4 4 4 4 5
        5 5 5 5 5 5 5 5 5


        #include<stdio.h>
        #include<math.h>

        int main()
        {
            int i,j,n,k,l;
            printf("Enter no:");
            scanf("%d",&n);

            // for the upper half
            for( i = n ; i >= 1; i--)
            {
                // first right angled triangle
                for( j = n;j >= i; j--)
                    printf("%d ",j);

                // second inverse triangle in the middle
                for(k = 1; k <= (i-1)*2-1; k++)
                    printf("%d ",i);

                // for the last right angled triangle
                for( l = i; l <= n; l++){
                    if(l==1)
                        continue;
                    printf("%d ",l);
                }

                printf("\n");
            }

            // for the mirror image part
            for(i=2;i<=n;i++)
            {
                // same code as above
                for(j=n;j>=i;j--)
                    printf("%d ",j);
                for(k=1;k<=(i-1)*2-1;k++)
                    printf("%d ",i);
                for(l=i;l<=n;l++){
                    printf("%d ",l);
                }
                printf("\n");
            }
            return 0;
        }

    2. Pascal's triangle

        - without using array
        - with formula

        1
        1  1
        1  2  1
        1  3  3  1
        1  4  6  4  1


        #include<stdio.h>
        #include<math.h>

        int main()
        {
            int i,j,n,a;
            printf("Enter no:");
            scanf("%d",&n);

            for( i = 0; i < n; i++){
                a = 1;

                for(j = 0; j <= i; j++){

                    if(j == 0) printf("%-3d", a);
                    else{

                        a = a*(i - j + 1)/j;
                        printf("%-3d", a);
                    }
                }

                printf("\n");

            }
            return 0;
        }

    3. Actual and formal parameters

        - swap(a , b) -> actual paramteres
        - void swap(int a, int b) -> formal parameters

    4. Types of function according to argument and return type

        - Argument with return type

            int fact(int)

        - Argument without return type

            void swap(int, int)

        - No argument but return type

            ch = getchar()

        - No argument no return type

            clrscr()
