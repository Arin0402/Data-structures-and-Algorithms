

1 we can only concatenate tuple with tuple
2 we can not create single valued tuples. for creating single valued tuples, we have place comma at the end
    like this -> ('str',) 

3 whenever we place * infront of a variable, then it tries to convert it into tuple. This is called args
    - for ex =  a = [1,2,3,4]

                *a
                print(a)

                -> output = (1,2,3,4) -> tuple formed

    - * tries to convert the variable into tuple, if it is possible.

    - we can concatenate two tuples using this

        b = (1,2,3)

        b = (*b, *b)  OR  b + b
        print(b)        

        output -> (1,2,3, 1,2,3)

        - if we do without * i.e (b, b)

            then output will be ((1,2,3), (1,2,3))

4  ** is used for dictionary
    - {**d1, **d2}

    - d1 + d2 is not possible

5 Anything non-zero or non-empty is True, when we covert it into bool

    - bool('') -> False
    - bool('adf') -> True
    - bool( [()] ) -> True (list is not empty)

6. List comprehension

    // Syntax 

    1.[output for-loop]

        a = [4, 'hi']
        b = [ val*2 for val in a]
        
        output -> [8, 'hihi']

    2. [output for-loop if-condition]

        a = [1,2,3,4,5,6,7,8,9,10]
        b = [val for val in a  if  val%2 == 0]

        output -> [2, 4, 6, 8, 10] (all the numbers which are even)
    
    3. [ ternary condition  for-loop]  // (for if else condition )

        a = [1,2,3,4,5,6,7,8,9,10]
        b = [val*2 if val%2 == 1 else val//2 for val in a]
        output -> [2, 1, 6, 2, 10, 3, 14, 4, 18, 5]

    4. Task -> multiply by 2 if odd otherwise check if it is less than 20 then divide by 2, else do nothing.

        a = [1,2,3,4,5,6,7,8,9,100]
        b = [val*2 if val%2 == 1 else ( val//2 if val < 20 else val )  for val in a]

        output -> [2, 1, 6, 2, 10, 3, 14, 4, 18, 100]

7. Dictionary comprehension

    a = [1,2,3,4,5,6,7,8,9,100]
    b = { val : val*2 for val in a if val%2 == 0}

8. printing data in dictionary

    for key, value in b.items():
        print(key, value)

9. 
    def fun(x = 10, *v, **u):        
        return [i*x for i in v], u

    
    // 3 goes in x
    // 6, 8 goes in v (tuple)
    // somedata goes in u (dictionary)
    fun(3, 6, 8, somedata = [3,4,5,6])

    output -> ([18, 24], {'somedata': [3, 4, 5, 6]})

10. Python functions can be 

    - assigned as a value

        def abc():
            print('hi')

        k = abc;

        k()

        output -> hi

    - taken as input argument in another function

        def xyz(f):
            f();

        // passing abc as function
        xyz(abc)

        output -> hi
    
    - defined inside another function
    - return a function as output from another function

11. Annonymous function - Lambda expression

    - syntax:

        lambda inp_args : output (returned)

    - It's always one-liner
    - always returns
    - Input arguments can be multiple, optional, keyword , named etc.
    - output can be simple/conditional/comprehension etc.

    - ex - 

        1.  single argument

            doubler = lambda x : x*2
            doubler(45)

            output -> 90

        2.  multiple arguments

            doubler = lambda x,y : x*y
            doubler(45,2)

        3. without arguments

            doubler = lambda : 5
            doubler()

            output -> 5

        4. if we use print in lambda then nothing will be returned, only it will get printed

            doubler = lambda : print('hi')
            k = doubler()

            print(k)

            output -> 
                        'hi'
                        None

        5.  oddeve =  lambda x : 'odd' if x%2 else 'even'
            
            oddeve(4)

            output -> 'even'    
12. Numpy

    - accessing the first columns of all the 2d matrixes

    a = np.array( [ [[1,2], [3,4]], [[1,2], [3,4]], [[1,2], [3,4]]])

    // first : is for selecting all the matrixes
    // second : is for selecting all the rows
    // 0:1 for selecting the first column
    
    a[:,:,0:1]

    output

        - array([[[1],
                    [3]],

                [[1],
                    [3]],

                [[1],
                    [3]]])


13. We cannot give floating number as a increment in range function

    ex - list(range(1, 11, 1.5)) -> this will not work

    We can give floating number as a increment in arange function

    ex - np.arange(1, 11, 1.5) -> this will work

        output -> array([ 1. ,  2.5,  4. ,  5.5,  7. ,  8.5, 10. ])

14. generate random values using Numpy  

    // generate 4 random values between 1 to 100
    np.random.randint(1, 100, 4) 

    // !--------------------------IMP-----------------!
    when we want to control the randomness, i.e we want same numbers to be generated every time we run the random command
    then for that we have to write

    np.random.seed(1) // we can give any number in the seed function as parameter, it doesn't matter
    np.random.randint(1, 100, 200)

    Doing this will generate the same random number every time we run the command
    This is requiured when we are testing an algorithm on random data and we don't want our data to be changed.   

15. To generate random values between 0.0 and 1.0
    
    np.random.rand(3, 4) -> here 3,4 is the shape. i.e matrix of size 3x4

16. create matrix using Numpy

    a = np.arange(1, 26).reshape(5, 5)

    array([[ 1,  2,  3,  4,  5],
       [ 6,  7,  8,  9, 10],
       [11, 12, 13, 14, 15],
       [16, 17, 18, 19, 20],
       [21, 22, 23, 24, 25]])

17. sum of all rows of a matrix

    a.sum(axis = 1) -> axis = 1 meaning rows , axis = 0 meaning cols



