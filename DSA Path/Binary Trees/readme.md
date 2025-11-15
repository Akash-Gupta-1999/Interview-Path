-   Learning
    -   types of binary Tree
        1.  Full Binary Tree : each node has eithee 0 or 2 child nodes
        2.  Complete Binary Tree : 
            -   All levels are completely filled Except last level
            -   In the last level, nodes are filled from left to right without gaps.
        3.  Perfect Binary Tree : All leaf nodes are at same level
        4.  Balanced Binary Tree : height of tree at max logN
        5.  Degenerate Tree : A skewed Tree (every node has one children)  
    -   Implement a Simple Tree (Insertion and Traversal)
    -   Can we Construct a Unique Binary Tree ?
        1.  Preorder and Postorder Given -> No
            -   Why?
                -   Preorder gives you the root first.
                -   Postorder gives you the root last.
                -   But neither tells you where the left subtree ends and the right subtree begins.
        2.  Inorder and Preorder Given -> Yes
        3.  Inorder and Postorder Given -> Yes
        4.  why preorder and postorder with inorder ?
            -   Postorder always gives the root last.
            -   Inorder again helps you split nodes into left and right subtrees.
            -   Using postorder root + inorder split, you can uniquely construct the tree (just recursion in reverse order).
            -   Works same as preorder+inorder, but root comes from end instead of start.
-   Traversals
                     10
                    /  \
                   5    15
                  / \   / \
                 3   7 12 18
    -   Depth First Search
        -   DFS explores as deep as possible before backtracking.
        -   Inorder Traversal ( Left → Root → Right )
            -   Visit the left subtree first
            -   Then visit the root
            -   Finally visit the right subtree
            -   3,5,7,10,12,15,18
            -   Essentially gives sorted order in a Binary Search Tree (BST).
        -   Preorder Traversal (Root → Left → Right)
            -   Visit the root first
            -   Then traverse left subtree
            -   Then traverse right subtree
            -   10,5,3,7,15,12,18
            -   Useful for copying / serializing a tree.
        -   Postorder Traversal (Left → Right → Root)
        -   Traverse the left subtree first
        -   Then traverse the right subtree
        -   Finally visit the root
        -   3,7,5,12,18,15,10
        -   Useful for deleting a tree safely (children before parent).
    -   Breadth First Searcg
        -   BFS explores level by level using a queue.
        -   Also called Level Order Traversal.
        -   10,5,15,3,7,12,18
    1.  Preorder_dfs : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    2.  Inorder_dfs : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    3.  Postorder_dfs : https://leetcode.com/problems/binary-tree-postorder-traversal/
    4.  Level order Traversal : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
    5.  preorder_dfx Iterative : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    6.  inorder_dfs_itr : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    7.  postorder_itr_2stack : https://leetcode.com/problems/binary-tree-postorder-traversal/
    8.  postorder_itr_1stack : https://leetcode.com/problems/binary-tree-postorder-traversal/
    9.  Preorder,inorder and postorder in 1 Traversal
-   Medium
    1.  Height of a binary tree : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
    2.  Is Balanced : https://leetcode.com/problems/balanced-binary-tree/description/
    3.  Diameter : https://leetcode.com/problems/diameter-of-binary-tree/description/
    4.  Maximum Path sum : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
    5.  is same tree : https://leetcode.com/problems/same-tree/
    6.  Zigzag Traversal : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
    7.  Boundary Traversal : https://takeuforward.org/plus/dsa/problems/boundary-traversal
    8.  Vertical order Traversal : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
    9.  Top view : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
    10. Bottom View : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    11. right view/left view : https://leetcode.com/problems/binary-tree-right-side-view/
    12. Symmetric Tree : https://leetcode.com/problems/symmetric-tree/
-   Hard
    1.  Path to all Leaf Nodes : https://takeuforward.org/plus/dsa/problems/print-root-to-note-path-in-bt
    2.  LCA of Binary Tree : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
    3.  Max width in a Complete binary Tree : https://leetcode.com/problems/maximum-width-of-binary-tree/
    4.  Children Sum Property : https://takeuforward.org/plus/dsa/problems/children-sum-property-in-binary-tree
    5.  Convert tree to Children sum tree : https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
    6.  All Nodes at Distance K : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
    7.  Burn BT : https://takeuforward.org/plus/dsa/problems/minimum-time-taken-to-burn-the-bt-from-a-given-node
    8.  Count Nodes in Complete Binary Tree : https://leetcode.com/problems/count-complete-tree-nodes/description/
    9.  Construct Tree with Inorder and Preorder : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    10. Construct Tree with Inorder and Postorder : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
    11. Serialize & Deserialize : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
    12. Morris Inorder Traversal : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    13. Morris Preorder Traversal : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    14. Flatten Binary Tree to a Linked List : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
        -   Rec Approach // 0(N) Time, o(N) Space
        -   Iterative Approach // O(N) Time, O(N) space
        -   Morris based Approach // O(N) Time, O(1) space