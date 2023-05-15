## Day 15

# Selection sort

    - Selection sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and moving it to the sorted portion of the list. 

    - The algorithm maintains two subarrays in a given array.

        The subarray which already sorted. 
        The remaining subarray was unsorted.
        In every iteration of the selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the beginning of the sorted subarray. 

        After every iteration sorted subarray size increase by one and the unsorted subarray size decrease by one.

        After the N (size of the array) iteration, we will get a sorted array.

    -   void selectionSort(int array[], int size) {
            for (int i = 0; i < size - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < size; j++) {
                    if (array[j] < array[minIndex]) {
                        minIndex = j;
                    }
                }
                swap(array[i], array[minIndex]);
            }
        }

    - TC -> O(N^2) 
    - Selection sort makes O(n) swaps
    - Selection sort makes the minimum swaps, so whenever the swap operation is costly, we use selection sort.


## Is Selection Sort Algorithm stable?

    - The default implementation is not stable. However, it can be made stable.

    - Selection sort works by finding the minimum element and then inserting it in its correct position by swapping with the element which is in the position of this minimum element. This is what makes it unstable.

    - Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element one step forward(shift all elements to left by 1). 
    In simple terms use a technique like insertion sort which means inserting element in its correct place. 

## Is Selection Sort Algorithm in place?

    - Yes     

## Advantages of Selection Sort

    - It is stable
    - No extra space
    - Works well with small datasets.
    - It is easy to modify to sort in ascending or descending order.

## Disadvantages of the Selection Sort Algorithm:

    - Selection sort has a time complexity of O(n^2) in the worst and average case.
    - Does not work well on large datasets.
    - Selection sort has poor cache performance and hence it is not cache friendly.
    - Not adaptive, meaning it doesn’t take advantage of the fact that the list may already be sorted or partially sorted
    - It is not a parallelizable algorithm, meaning that it cannot be easily split up to be run on multiple processors or cores.

# Insertion sort

    - Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

    - Insertion sort is adaptive in nature, i.e. it is appropriate for data sets which are already partially sorted.

    - Insertion sort is a comparison-based algorithm.

    -   procedure insertionSort(arr):

            for i = 1 to n-1
                
                j = i

                while j - 1 >= 0 and arr[j - 1] > arr[j]
                    swap arr[j-1] with arr[j]
                    j--

                end while
            end for

        end function

    - Time Complexity of Insertion Sort
        worst case -> O(N^2)
        average case -> O(N^2)
        best case is -> O(N).

## Recursive Implementation

    void recursiveInsertionSort(vector<int>& arr, int n)
    {        
        if (n <= 1) {
            return;
        }
                
        recursiveInsertionSort(arr, n - 1);
                
        j = n-1;

        while j - 1 >= 0 and arr[j - 1] > arr[j]
            swap arr[j-1] with arr[j]
            j--

        end while
    }    

## What are the Boundary Cases of the Insertion Sort algorithm?

    Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. 

## What are the Algorithmic Paradigm of Insertion Sort algorithm?

    Insertion Sort algorithm follows incremental approach.

## Is Insertion Sort a stable algorithm?

    Yes

## When is the Insertion Sort algorithm used?

    Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

## What is Binary Insertion Sort? 

    We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. In normal insertion, sorting takes O(i) (at ith iteration) in worst case. We can reduce it to O(logi) by using binary search. The algorithm, as a whole, still has a running worst case running time of O(n^2) because of the series of swaps required for each insertion. Refer this for implementation.

## Insertion sort for linked list

    - Take three pointers prev2, prev and curr.
    - put a pointer at the start and compare the two pointers to make links

## Is Insertion Sort a Greedy Algorithm?

    No, insertion sort is not a greedy algorithm.

    A greedy algorithm is an algorithm that makes a locally optimal choice at each step with the hope of finding a global optimum.

    Insertion sort does not make any locally optimal choice but instead inserts each element in its correct position to achieve the global optimum.

# Merge sort

    - Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays, sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.

    -   step 1: start

        step 2: declare array and left, right, mid variable

        step 3: perform merge function.
            if left > right
                return
            mid= (left+right)/2
            mergesort(array, left, mid)
            mergesort(array, mid+1, right)
            merge(array, left, mid, right)

        step 4: Stop

    - TC - O(N log(N))

    - Recurrence relation -> T(n) = 2T(n/2) + θ(n)

## Is Merge sort Stable?

    Yes

## How can we make Merge sort more efficient?

    - Merge sort can be made more efficient by replacing recursive calls with Insertion sort for smaller array sizes, where the size of the remaining array is less or equal to 43 as the number of operations required to sort an array of max size 43 will be less in Insertion sort as compared to the number of operations required in Merge sort.

## Applications of Merge Sort: 

    - Sorting large datasets

    -  External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory. Merge sort can be adapted to work with external storage devices like hard drives or tape drives, making it useful for applications like sorting large files or processing data streams.

    - Merge sort is a naturally parallelizable algorithm, which means it can be easily adapted to work with multiple processors or threads. This makes it useful for applications that require high-performance computing, such as scientific simulations or financial modeling.

    - Merge sort is a stable sorting algorithm, This makes it useful in applications where preserving the original order of equal elements is important, such as in databases or financial systems.

## Advantages of Merge Sort:

    - Stability
    - Guaranteed worst-case performance
    - Parallelizable

    - Memory efficient: Merge sort has a space complexity of O(n), which means it can sort datasets that are larger than the available memory on a machine. This makes it useful for applications where memory usage is a concern.

    - Versatility: Merge sort can be used to sort a wide range of data types, including integers, floating-point numbers, and strings.

    - Adaptability: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data. This makes it useful in a variety of real-world applications.

## Drawbacks of Merge Sort:

    - Space complexity

    - Recursive algorithm: Merge sort is a recursive algorithm, which can result in a large number of function calls and stack usage for very large datasets. This can cause stack overflow errors or other performance issues.

    - Not in-place

    - Not always optimal for small datasets: Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort, for small datasets. This can result in slower performance for very small datasets.

    - Complexity of implementation

## A list of n string, each of length n, is sorted into lexicographic order using the merge-sort algorithm. The worst case running time of this computation is O (n^2 log n)  .

## Given two sorted list of size m and n respectively. The number of comparisons needed the worst case by the merge sort algorithm will be m + n - 1