# Cache memory

    - Cache memory is a small, high-speed memory located close to the CPU (Central Processing Unit) that stores frequently accessed data and instructions. Its main purpose is to reduce the time the CPU takes to access data from the main memory (RAM), which is relatively slower.

# How Cache Memory Works:

    1. Data Access Prediction:

        - When the CPU needs to read or write data, it first checks whether the data is in the cache (called a cache hit). If it's not found (a cache miss), it fetches the data from RAM and stores a copy in the cache for faster access next time.

    2. Hierarchy Levels:

        - Cache memory is typically organized in levels:

            L1 (Level 1): Fastest and smallest, built directly into the CPU chip.
            L2 (Level 2): Larger and slightly slower, can be on the CPU chip or close to it.
            L3 (Level 3): Shared among CPU cores, larger but slower than L1 and L2.

    3. Mapping Techniques (how data is stored):

        - Direct-mapped cache: Each block of memory maps to exactly one cache line.
        - Set-associative cache: Memory blocks can map to any of a set of cache lines.
        - Fully associative cache: Memory blocks can go into any cache line.

    4. Replacement Policies (what to discard when cache is full):

        - LRU (Least Recently Used): Replaces the data not used for the longest time.
        - FIFO (First In First Out): Replaces the oldest data in the cache.
        - Random Replacement: Replaces data at random.

    5. Write Policies:

        - Write-through: Data is written to both the cache and main memory simultaneously.
        - Write-back: Data is written only to the cache first, and to RAM later when the cache line is replace
        
# Locality of reference

    - Cache underlying principle is the locality of reference

    - In the locality of reference, huge data is placed in a small area (data which is needed) so that the access time will be less and the performance will be higher.

    - There are two main types:

    1. Temporal Locality ("Time-based")    

        Definition: 
            - If a memory location is accessed, it's likely to be accessed again soon.
        Example: 
            - In a loop, the same variable is accessed repeatedly.

            for (int i = 0; i < 1000; i++) {
                sum += array[i];
            }

    2. Spatial Locality ("Location-based")

        Definition: 
            - If a memory location is accessed, nearby memory locations are likely to be accessed soon.
        Example: 
            - Iterating through an array accesses consecutive memory locations.

            for (int i = 0; i < 1000; i++) {
                process(array[i]);
            }

# Why It Matters for Cache:

    - Caches work well because of locality.
    - When data is loaded into cache, surrounding data is also fetched (spatial).
    - Frequently used data stays in cache for quick reuse (temporal).