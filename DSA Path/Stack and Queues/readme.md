-   Learning
    1.  Implement Stack using Array
    2.  Implement Queue using Array
    3.  Implement Stack using queue : https://leetcode.com/problems/implement-stack-using-queues/
    4.  Implement stack using LinkedList
    5.  Implement Queue using LinkedList
    6.  Implement Queue using Stack : https://leetcode.com/problems/implement-queue-using-stacks/
    7.  Valid Parenthesis : https://leetcode.com/problems/valid-parentheses/
    8.  Implement Min Stack : https://leetcode.com/problems/min-stack/
-   Prefix, Infix, Postfix Conversions
    -   Facts
        -   Operators : ^,*,/,+,- ; ^ : right assosciative a^b^c == a^(b^c) ; +,-,*,/ : left assosciative = (a+b)+c 
        -   Operands :  a-z,A-Z,0-9
        -   priority
            ^   - 3 |
            /,* - 2 |   Decreasing Order
            +,- - 1 |
                   \_/
        -   Infix : (p+q)*(m-n) : Most Programming Languages Understand
        -   Prefix : *+pq-mn : used in programming language lisp, also used in trees 
            -   a+b*(c^d-e) = a+b*((^cd)-e) = a+b*(-^cde) = a+(*b-^cde) = +a*b-^cde
        -   Postfix : pq+mn-* : used in stack based Calculators
            -   a+b*(c^d-e) = a+b*((cd^)-e) = a+b*(cd^e-) = a+(bcd^e-*) = abcd^e-*+
    1.  Infix to Postfix
        -   Operands (a, b, 1, 2 …) → add to output.
        -   ( → push to stack.
        -   ) → pop to output until (, then discard both.
        -   Operators (+ - * / ^): 
            -   While stack top has higher precedence, or equal precedence and op is left-associative → pop to output.
            -   Then push current operator.
        -   End → pop remaining operators to output.
    2.  Infix to Prefix
        -   Reverse the infix expression ; Swap ( ↔ ) while reversing.
        -   Convert the reversed expression to Postfix
            -   Operands → add to output.
            -   ( → push.
            -   ) → pop until (.
            -   Operators (+ - * /) → here we treat them as right-assosciative.
            -   Operator ^ → here we treat it as left-associative (different from infix→postfix case).
            -   Push the operator.
            -   At the end → pop remaining operators.
        -   Reverse the postfix result → that’s your prefix expression.
    3.  Postfix to Infix
        -   Initialize an empty stack.
        -   Scan from left → right in the postfix expression:
            -   If operand (a, b, 1, 2, …) → push it as a string.
            -   If operator (+, -, *, /, ^):
            -   Pop op2 = top of stack.
            -   Pop op1 = next top of stack.
            -   Form "(op1 operator op2)".
            -   Push the new string back.
        -   At the end, the stack has only one element → that is the final infix expression.
    4.  Prefix to Infix
        -   Initialize an empty stack.
        -   Scan from right → left in the prefix expression:
            -   If operand (a, b, 1, 2, …) → push it as a string.
            -   If operator (+, -, *, /, ^):
            -   Pop op1 = top of stack.
            -   Pop op2 = next top of stack.
            -   Form "(op1 operator op2)".
            -   Push the new string back.
        -   At the end, the stack has only one element → that is the final infix expression
    5.  Postfix to Prefix
        -   Traverse left to right.
        -   If operand → push onto stack.
        -   If operator →
            -   Pop op2 then op1.
            -   Form new string = operator + op1 + op2.
            -   Push it back.
        -   At the end, the stack’s top = final prefix expression.
    6.  Prefix to Postfix
        -   Scan prefix from right to left.
        -   If operand → push to stack.
        -   If operator →
            -   Pop two operands from stack (first pop = left, second pop = right).
            -   Form new expression = operand1 + operand2 + operator.
            -   Push back to stack.
        -   At the end → the stack’s top has the postfix expression.
-   Monotonic Stack
    1.  Next Greater Element : https://leetcode.com/problems/next-greater-element-i/ 
    2.  Next Greater Element 2 : https://leetcode.com/problems/next-greater-element-ii/
    3.  Next Smaller Element : https://www.geeksforgeeks.org/dsa/next-smaller-element/
    4.  Number of NGE to right : https://www.geeksforgeeks.org/dsa/number-nges-right/
    5.  Trapping Rainwater : https://leetcode.com/problems/trapping-rain-water/description/
    6.  Sum of minimum in subarray : https://leetcode.com/problems/sum-of-subarray-minimums/
    7.  Asteroid Collision : https://leetcode.com/problems/asteroid-collision/description/
    8.  Sum of Subbarray range : https://leetcode.com/problems/sum-of-subarray-ranges/
    9.  Remove K digits : https://leetcode.com/problems/remove-k-digits/description/
    10. Largest Rectangle in a Histogram : https://leetcode.com/problems/largest-rectangle-in-histogram/
    11. Maximal Rectangle : https://leetcode.com/problems/maximal-rectangle/
-   Implementation
    1.  Sliding Window Maximum : https://leetcode.com/problems/sliding-window-maximum/description/
        -   heap + priority queue approach : Time : O(nlogn) / space : O(n+k)   
        -   optimized - Monotonic deque
    2.  Stock Spanner : https://leetcode.com/problems/online-stock-span/
    3.  Celebrity Problem : https://takeuforward.org/plus/dsa/problems/celebrity-problem
    4.  LRU cache : https://leetcode.com/problems/lru-cache/description/
    5.  LFU cache : https://leetcode.com/problems/lfu-cache/description/