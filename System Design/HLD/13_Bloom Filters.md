# Bloom filters


# The problem 

    - Imagine if we are registering for a domain and we want to check if the domain name is available or not. 
    - For this, the request has to go to backend and there it has to be checked with billion of records to check if the user entered domain name exists or not
    - This can happen multiple times    

    - So the core problem is 

        How can we check membership in a set using minimal memory and fast access, especially when we can tolerate a small probability of error?

# The Solution

    - A Bloom filter helps you quickly check if something might be in a big list, using very little space, and it’s okay if it sometimes says “yes” by mistake — but never says “no” by mistake.

    -  The Solution — Bloom Filter:

        A Bloom filter is a clever tool that lets you check if something might be in your list, using very little memory.

        It can say: "Maybe it's there" ✅
        Or: "Definitely not there" ❌

    - We may use other solutions such as hasset , trie, binary serch etc but these would consume a lot of memory and time complexity is also not that efficient

# Example

    - Let’s say you're building a spam detector. You want to avoid checking emails you've already processed.
    - Instead of storing every email, you use a Bloom filter.

        - If the filter says "no" → you’re 100% sure it’s new.
        - If the filter says "yes" → you’re probably seen it before.

    So you avoid doing extra work most of the time!

# Time complxity

    1. Insert an element

        You compute k hash functions and set k bits in a bit array.

        Time Complexity: ✅ O(k)
        (where k is the number of hash functions, typically a small constant like 7 or 10)

    2. Check if an element might be present
        
        You again compute k hash functions and check k bits.
        Time Complexity: ✅ O(k)
    
    - This can be called as O(1) in general

# The TradeOff

    - It is memory vs efficiency
    - We might get false positives but we are saving upon a lot of memory as we require only hash functions and the arrays

# The disadvantages

    1. Deciding the size of the arrays, Or the deciding the good hash function can be challeinging
    2. Deletion support is not there as we can't directltly delete the bit from the array as it may being used by another string. But this disadvantage is being overcomed by "Counting bloom filter"

# Applications

    1. Web crawler

        - a web crawler needs to visit hundreds of websites to extract the data so it can be used to check if the link has been visited or not

    2. Databases – Avoiding Unnecessary Disk Reads

        Example: Apache Cassandra, HBase, Bigtable

        Problem: Reading from disk is slow. You want to check: “Does this record exist in this file?”
        Solution: Use Bloom filters to avoid checking files that definitely don’t contain the data.

        ✅ Reduces expensive disk I/O.

    3. For the one hit wonders

        - We want to use the cache of browser efficiently store only that data that is being used by the user more frequently.
        - So we would avoid adding data that is rarely searched by the user and we can check that with the help of bloom filters.
        - We only add the data to the cache if it is present in the bloom filter ( If it is in the bloom filter that means it has already been searched)


# Note:

    - We can also have mulitple layers of bloom filters. That is instead of having only one array, we can have mulitple layers to reduce the chances of false potiives

# Video

    - https://www.youtube.com/watch?v=nt7MHw1bQ_c

# What is a Counting Bloom filter?

    Allows deletion by using counters instead of bits.

# What is a Cuckoo Filter and how does it differ from a Bloom filter?

    Cuckoo Filter supports deletion and may use less space at similar false positive rates.