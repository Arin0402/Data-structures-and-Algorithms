// https://leetcode.com/discuss/post/1837497/goldman-sachs-coderpad-find-the-largest-fx8uh/

/*

A forest is represented with a hashmap. This hashmap has this key -> value relationship: child -> parent.
Every node has a unique integer element. I needed to find out the largest tree's root node. If there is a tie, return the smallest root.

The tree with the highest number of nodes, is the largest one. The edges are directed from parent to child.

Input:
{{1 -> 2}, {3 -> 4}}

*/

// I first found out the roots present in the forest. Then created an adjacency list and applied BFS to count the nodes. Maintained the maximum count and root with the largest tree in two variables.

// OR

// We can use Disjoint set also. 
// Make two arrays -> parent and size. Keep finding the ultimate parent and updating the size in the size array