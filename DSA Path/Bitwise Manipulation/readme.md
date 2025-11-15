-   Learning
    1.  convert Decimal to Binary and Binary to Decimal
    2.  Range 
        -   A 32-bit signed int uses two’s complement representation.
        -   Range: −2^31 to 2^31−1(−2147483648 to 2147483647)
                −2^31 to 2^31−1(−2147483648to2147483647)
        -   Why not 2^31? → Because one extra slot is taken by −2^31.
        -   n-bit signed int → range is −2^(𝑛−1) to 2^(𝑛−1)−1
        -   How negatives are stored: (2's Compliment)
            1.  Take the positive number’s binary.
            2.  Invert all bits (1 → 0, 0 → 1).
            3.  Add 1.
            Example: -5
            -   +5 in binary:     00000101
                Invert bits:      11111010
                Add 1:            11111011   ← this is how −5 is stored
    3.  Operators
        -   AND (&) → Sets bit to 1 if both bits are 1.
            Example: 5 & 3 = 0101 & 0011 = 0001 = 1

        -   OR (|) → Sets bit to 1 if either bit is 1.
            Example: 5 | 3 = 0101 | 0011 = 0111 = 7

        -   XOR (^) → Number of 1's are odd then 1 if they are even then 0.
            Example: 5 ^ 3 = 0101 ^ 0011 = 0110 = 6
        
        NOTE : Signed bit handled as normal bit only for &,|,^  ----> -ve&+ve = -ve, -ve|+ve = -ve, -ve^-ve = +ve

        -   Left Shift (<<) → Shifts bits left, filling with 0 (multiplies by 2).
            Example: 5 << 1 = 0101 << 1 = 1010 = 10
            x << k =========== x * 2^k
            Note : There is a chance of overflow when (2^31-1)<<1 - As it gets out of range

        -   Right Shift (>>) → Shifts bits right, sign bit preserved for signed numbers (divides by 2).
            Example: 5 >> 1 = 0101 >> 1 = 0010 = 2
            x >> k ============ x/2^k
            Note : Sign bit is preserved for most Compilers

        -   NOT (~) :
            1.  Flips all bits of the number.
            2.  The sign bit (most significant bit) decides if the result is positive or negative.
            3.  If the result is negative → it is stored in two’s complement form.
            4.  If the result is positive → nothing extra is needed.
            Examples:
            -   +5 stored as:   00000101
                Flip bits:      11111010  (MSB=1 → negative)
                Two’s comp:     00000110  → 6
                Answer:         -6
            -   Step 1: +3 in binary:     00000011
                Step 2: Take 2’s comp:    11111101  → this is how -3 is stored
                Now apply ~:
                Flip bits:                00000010  (MSB=0 → positive)
                Answer:                   2
    4.  Swap 2 Numbers
    5.  Check if ith bit is set or not (x & (1<<i)) or ((x>>i) & 1)
    6.  Set the ith bit (x = x | (1<<i))
    7.  Clear the ith bit (x = x & ~(1<<i))
    8.  Toggle the ith bit (x = x ^ (1<<i))
    9.  check if number is odd (x&1 == 1) -> odd, (x&1 == 0) -> even
    9.  Remove the last set bit (x = x & (x-1))
        -   x - 1 flips all bits after the rightmost set bit (including that bit).
        -   x & (x - 1) keeps higher bits same but clears that rightmost set bit.

                👉 Example:

                x     = 1100 (12)
                x-1   = 1011 (11)
                x&(x-1)=1000 (8)   // last set bit removed
        -   This trick is widely used to remove last set bit or count set bits efficiently.
    10. Check if the number is power of 2 -> (x & (x-1) == 0) : https://leetcode.com/problems/power-of-two/description/
    11. Set the rightmost bit -> (x = x | (x+1))
    11. Count Number of Set bits
    12. Add 2 numbers without + operator
    13. Divison of 2 numbers : https://leetcode.com/problems/divide-two-integers/description/
-   Interview Questions
    1.  count number of minium bits to flip from A to convert B : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
    2.  Single Number - 1 : https://leetcode.com/problems/single-number/description/
    3.  Single Number - 2 : https://leetcode.com/problems/single-number-ii/description/
    4.  Single Number - 3 : https://leetcode.com/problems/single-number-iii/
    5.  Power Set : https://leetcode.com/problems/subsets/
    6.  XOR of given Numbers in Range l to r without iteration: https://www.youtube.com/watch?v=WqGb7159h7Q