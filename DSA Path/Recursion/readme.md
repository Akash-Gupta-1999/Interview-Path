-   Learning
    -   reverse an array using recursion
    -   is string palindrome ?
    -   Fibonacci Sequence // O(2^n)
-   Get a Good Hold
    1.  Recursive Atoi : https://leetcode.com/problems/string-to-integer-atoi/
    2.  Implement pow(x,n) : https://leetcode.com/problems/powx-n/
    3.  Count Good Numbers : https://leetcode.com/problems/count-good-numbers/description/
    4.  Sort Stack using recursion : https://www.geeksforgeeks.org/dsa/sort-a-stack-using-recursion/
    5.  Reverse a Stack using recursion : https://www.geeksforgeeks.org/dsa/reverse-a-stack-using-recursion/
-   Subsequence Problems (BackTracking)
    1.  Generate all binary strings : https://www.geeksforgeeks.org/dsa/generate-binary-strings-without-consecutive-1s/
    2.  Generate Parenthesis : https://leetcode.com/problems/generate-parentheses/
    3.  Power set : https://leetcode.com/problems/subsets/description/
    4.  count subsequence with sum k : https://takeuforward.org/plus/dsa/problems/count-all-subsequences-with-sum-k
    5.  Check if subsequence with sum k exists : https://takeuforward.org/plus/dsa/problems/count-all-subsequences-with-sum-k
    6.  Combination sum - 1 : https://leetcode.com/problems/combination-sum/description/
    7.  Combination sum - 2 : https://leetcode.com/problems/combination-sum-ii/
    8.  Subset sum - 1 : https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
    9.  Subset sum - 2 : https://leetcode.com/problems/subsets-ii/
    10. Combination sum - 3 : https://leetcode.com/problems/combination-sum-iii/description/
    11. letter combinations of a phone number : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
-   Trying out All Combos
    1.  Palindrome Partitioning : https://leetcode.com/problems/palindrome-partitioning/description/
    2.  Word Search : https://leetcode.com/problems/word-search/
    3.  N queen : https://leetcode.com/problems/n-queens/description/
    4.  Rat in a Maze : https://takeuforward.org/data-structure/rat-in-a-maze/
    5.  Word Break : https://leetcode.com/problems/word-break/description/
    6.  M coloring Problem : https://takeuforward.org/data-structure/m-coloring-problem/
    7.  Solve Sudoku : https://leetcode.com/problems/sudoku-solver/description/
    8.  add Expression : https://leetcode.com/problems/expression-add-operators/


-   Cheatsheet
    -   Phase I : Learning and Implementation
        1.  Type 1 : Implement Atoi : simple but good question (not recursive)
        2.  Type 2 : Implement pow(x,n), Good Numbers : Maths,iterative
        3.  Type 3 : Sort stack, Reverse Stack : double recursion

    -   Phase II : Generate Subsequences with Conditions 
        1.  Type 1 : Generate binary strings, Balanced Parenthesis : double recursion for binary choice E.x. ( or ), 0 or 1
        2.  Type 2 : Power Set,countsubseqwithsumk, checksubseqwithk, combinationsum1, subsetsum1 : double recursion for including & Excluding Elements
        3.  Type 3 : combinationsum2, subsetsum2 : backtracking,single recursion with duplicates handling
        4.  Type 4 : combinationsum3, lettercombinationsofaphonenumber : u can use any of the 2 recur method but u need to build set on ur own and conditions are important

        NOTE : 2 methods to Generate All combinations in a set 
            -   one is double recursion, 
            -   another with a loop and single recursion. 
        But in first root case should be i == n, in second case no root case needed.

    -   Phase III : Trying out all possible arrangements with constraints
        1.  Type 1 : Palindrome Partitioning, Word Break 
            Palindrome : It is kind of MCM DP but in this u need to print all possible partitions if u just need minimum partitions then MCM DP will work. but Method is same as MCM.
            Word break : similar to word search but here u need to build words from dictionary and backtrack accordingly use DP to optimize if u just need to check if possible or not.
        2.  Type 2 : Word Search, Rat in a Maze : simple DFS with backtracking
        3.  Type 3 : N queen,M coloring, Solve Sudoku
            N Queen : classic backtracking but other quick good solution to check ifpossible is to use indexing arrays for row, col and 2 diagonals for left diag col-row and right diag col+row
            M coloring : similar to N queen but here u need to check for all colors for each node
            Solve Sudoku : similar to M coloring but here u need to check for all numbers from 1-9 for each empty cell
        4.  Type 4 : Add Expression : Really good question to understand how to build expression with operators and backtrack accordingly. also need to handle precedence of * operator with prev value.