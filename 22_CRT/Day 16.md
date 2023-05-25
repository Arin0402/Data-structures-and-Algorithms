## Day 16

# Internal working of map

    - In C++, map is typically implemented as a balanced binary search tree, specifically a red-black tree. The red-black tree is a self-balancing binary search tree.

    - Each node in the map contains a key-value pair, along with pointers to its left and right child nodes and a pointer to its parent node. Additionally, each node stores information about its color (red or black) for maintaining the balancing property of the red-black tree.
    
    - The red-black tree property ensures that the tree remains balanced. It enforces the following rules:

        Each node is either red or black.

        The root node is always black.

        No two adjacent nodes can be red.

        Every path from the root to a leaf contains the same number of black nodes (this ensures the tree remains approximately balanced).

# Internal working of unordered map

    - In C++, unordered_map is typically implemented as a hash table.

    - The unordered_map maintains a dynamic array of buckets. Each bucket is capable of holding multiple key-value pairs. The number of buckets is typically set based on the initial size or load factor specified during map creation.

    -  The map uses a hash function to convert each key into a hash code, which determines the index of the bucket where the key-value pair will be stored. The hash function should distribute the keys uniformly across the buckets to minimize collisions.

    - Since multiple keys can have the same hash code (collision), the map employs techniques to handle collisions. One common approach is to use separate chaining. Each bucket contains a linked list or other suitable data structure to store multiple key-value pairs that share the same hash code.

    -  When you insert a new key-value pair into the std::unordered_map, the hash function is applied to the key to determine the target bucket. If there are no collisions, the pair is simply added to the bucket. In case of a collision, the new pair is added to the appropriate bucket using the collision handling technique (e.g., appending to a linked list).

    -  During a lookup operation, the hash function is used to calculate the hash code of the provided key. Based on the hash code, the map identifies the corresponding bucket. Then, the map traverses the linked list (or other structure) within the bucket to find the desired key-value pair. This process allows for efficient retrieval of values based on the key.

    - When you remove an element from the std::unordered_map, the hash function is applied to locate the bucket. The key-value pair is then searched within the bucket's linked list, and if found, it is removed.

    - As the number of elements in the map increases or when the load factor threshold is reached, the std::unordered_map may resize the underlying bucket array to maintain efficient performance. The resizing process involves creating a new array with a larger size, rehashing all the key-value pairs, and redistributing them to the appropriate buckets.

# Red-Black tree

    - A red-black tree is a type of self-balancing binary search tree. It was introduced by Rudolf Bayer in 1972. . Red-black trees guarantee that the height of the tree remains balanced, providing efficient search, insertion, and deletion operations.

    - Here are the key properties of a red-black tree:

        - Every node is colored either red or black.
        - The root node is always black.
        - Every leaf (NIL or null node) is considered black.
        - If a node is red, both its children are black.
        - Every path from a given node to its descendant leaves contains the same number of black nodes. This property is known as the black-height property.

    - These properties ensure that the longest path from the root to any leaf is no more than twice as long as the shortest path. This guarantees that the tree remains balanced and provides an efficient worst-case time complexity of O(log n) for search, insert, and delete operations.

    - To maintain these properties, red-black trees employ a set of operations such as rotations and color changes during insertion and deletion. These operations ensure that the tree maintains balance while preserving the key properties.

    