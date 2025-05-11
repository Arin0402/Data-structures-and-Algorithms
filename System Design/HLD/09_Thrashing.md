# What is Thrashing

    - Thrashing is a situation in a computer system where excessive paging (swapping pages between RAM and disk) causes a significant drop in performance. It happens when the system spends more time swapping pages in and out of memory than executing actual processes.

    - If there is an increase in the number of processes submitted to the CPU for execution, then the CPU utilization will be increased. But by increasing the process continues at a certain time, the CPU utilization falls sharply and sometimes it reaches 0. This situation is said to be thrashing.

    - The CPU scheduler increases the degree of multiprogramming on finding a decrease in CPU utilization. The new processes start taking frames from each other processes thereby causing more page faults and a long queue for the paging device. Due to all this, CPU utilization decreases further thus making the CPU scheduler increase the degree of multiprogramming even more. This causes thrashing and also throughput decreases.

    - The effects of thrashing can be minimized by local replacement (priority replacement algorithm). So what happens in local replacement is that if one process starts thrashing it cannot steal frames from another process thereby causing the latter to thrash as well.

# Solutions to thrashing

    1. Reduce Multiprogramming:

        - Limit the number of processes in memory.
        - Suspend or swap out less important processes.

    2. Use a Better Page Replacement Algorithm:

        - Algorithms like Least Recently Used (LRU) reduce unnecessary swaps.

    3. Increase RAM:

        - More physical memory reduces the need for swapping.

    4. Working Set Model:

        - Allocate enough frames to each process based on its working set (the set of pages it actively uses).
        - Prevent processes from running if they exceed their working set size.
        - If a process has all the pages in its working set in memory, page faults are minimized.

        - How it works ?
            
            - For every process, keep track of the pages it has used in the last Δ time.                    
            - Count the number of unique pages in that time frame — this is the working set size.
            - Ensure that each process gets at least enough frames to hold its working set.
            - If the sum of all working sets exceeds total memory → reduce multiprogramming.

        - 🔧 How Do We Reduce Multiprogramming Using the Working Set Model?

            1. Suspend (Swap Out) Processes with Large or Growing Working Sets
            2. Do not admit new processes into memory if the current total working set size is close to or exceeding physical memory.
            3. Run processes with smaller working sets to improve throughput.

    5. Use Local Replacement Instead of Global Replacement:

        - Local: Each process replaces its own pages.
        - Global: Any page from any process can be replaced, which may lead to instability.