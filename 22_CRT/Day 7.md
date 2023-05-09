### Day 7

## 2D array

    - In memeory, 2d array is stored in sequemtial manner

    - int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12} -> This is also allowed

    - int arr[3][4] = {1,2,3,4,5,6} -> This puts values in the row serial wise and puts 0 at the remaining places

        output ->       1 2 3 4
                        5 6 0 0
                        0 0 0 0

    - int arr[][4] = {1,2,3,4,5,6} -> No row is declared so this puts values in the row serial wise and puts 0 at the remaining places

        output ->       1 2 3 4
                        5 6 0 0
                        
    - We have to declare the size of the column in 2d array

        - int arr[3][] -> This is not allowed
    
    - We can initialize the 2d array with all zeros by making it static

        static int arr[3][4]

        - by using static keyword, memory is created as global but the scope is not global

    
    - 3d array syntax -> int arr[3][3][4]
                                 ^  ^--- Rows and columns    
                                 |
                                 number of matrices


    - matrix multiplication m1 (r1, c1) , m2(r2, c2)

        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c2; j++)
            {
                c[i][j] = 0;

                for(int k = 0; k < c1; k++)
                    c[i][j] += a[i][k]*b[k][j];
            }
        }

    -  int arr[3][4] 

        - sizeof(a) -> 48 (3x4 x 4) (every interger takes 4 bytes)

        - sizeof(a[0]) -> 16 (every row has 4 integers and every integer takes 4 bytes)

        - sizeof(a[0][0]) -> 4 (every integer takes 4 bytes)

    - In 2d array, every row has its base address, a[0] will print the base address

    - a[i][j] =  *(*(a + i) + j) -> This is how 2d array is dereferenced

        - a contains the staring memory address
        - *(a + i) get the address of the starting of the particular row
        - *(*(a + i) + j) gets the value of that particular cell
    
    - Dynamic 2d array

        // This array holds the addresses of every row
        int **p = new int*[r];        //pointer array

        for(int i = 0; i < r; i++)
        {
            p[i] = new int [c];        //data array
        }


        // input and output is normal

        //free dynamic memory
        for(int i = 0; i < r; i++)        
            delete []p[i];        //data array

        delete []p;        //pointer





