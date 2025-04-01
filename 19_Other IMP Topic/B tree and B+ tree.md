- Both B-Tree and B+ Tree are self-balancing tree data structures commonly used in databases and file systems for indexing

# B-Tree

    - Keys and data (values) are stored in both internal and leaf nodes.
    - Searching can stop at any node where the key is found.
    - Internal nodes contain pointers to child nodes.
    - Not all leaf nodes are at the same level.
    - Since data is scattered across all nodes, searching is slower
    - Requires more rebalancing because data is stored at multiple levels.


# B+ Tree

    - Only keys are stored in internal nodes; actual data (values) are stored only in leaf nodes.
    - Internal nodes are used only for indexing.
    - Leaf nodes are linked together using pointers (forming a linked list), making range queries more efficient.
    - All leaf nodes are at the same level.
    - Search always goes to the leaf level, where actual data is stored.
    - Faster lookup for range queries due to linked leaf nodes.
    - Less rebalancing needed, as data is stored only in leaf nodes.


Feature	                            B-Tree	                                B+ Tree

Data Storage    	                Internal & Leaf Nodes	                Only Leaf Nodes

Search Efficiency	                Slower (data in internal & leaf nodes)	Faster (only in leaf nodes)

Range Queries	                    Inefficient	                            Efficient (linked leaf nodes)

Insertion/Deletion Complexity	    More complex	                        Easier

Traversal	                        Requires in-order traversal	            Faster (linked list in leaves)

Disk Access	                        Higher	                                Lower (better cache performance)
