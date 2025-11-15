/**************************************************************
 * Single Number Variants — Three Approaches + Detailed Intuition
 *
 * You asked for:
 *   1) A "32-length array" (bit counting) solution for the k=3 case.
 *   2) The classic O(1)-space bitmask trick (ones/twos) for k=3.
 *   3) A general solution for: "every number appears k times except one".
 *
 * PLUS: Detailed explanations in comments, including why/when each works
 * and why/when it fails.
 *
 * ----------------------------------------------------------------------
 * QUICK RECAP OF THE PROBLEMS:
 *
 * - Single Number II (LeetCode 137): Every value appears exactly 3 times,
 *   except for one value that appears exactly once — find that value.
 *
 * - Generalization: Every value appears exactly k times, except one value
 *   that appears exactly once (or, more generally, appears r times where
 *   r % k != 0) — find that value.
 *
 * ----------------------------------------------------------------------
 * APPROACH 1: Bit Counting with an array of 32 counters (k = 3)
 *
 * INTUITION:
 *   Think per-bit (bitwise) and ignore carries. Count, for each of the 32
 *   bit positions, how many numbers have that bit set. If all "other"
 *   numbers appear in multiples of 3, then (count_of_set_bits % 3) equals
 *   1 exactly at those bit positions that belong to the unique number.
 *   Reconstruct the answer by setting those bits.
 *
 * WHY IT WORKS (UNDER THE PROMISE):
 *   If every non-unique number contributes to a bit-position a multiple of 3,
 *   then modulo 3 they contribute 0. Only the unique number contributes +/-1
 *   at its 1-bits. Thus, count % 3 reveals the unique's bits.
 *
 * NEGATIVES (Two's Complement) — IMPORTANT DETAIL:
 *   Use unsigned masks (uint32_t) for bit checks and reconstruction. After
 *   reconstruction, casting the 32-bit pattern back to int yields the correct
 *   signed value, including negative results.
 *
 * WHEN IT FAILS:
 *   - If there are other numbers that appear NOT in multiples of 3 (e.g., some
 *     appear twice), their bits leak into the modulo and distort the result.
 *   - If the "unique" number actually appears r times with r % 3 == 0, then it
 *     disappears modulo 3 (indistinguishable).
 *
 * NOTE (Broader than you might think):
 *   If there is a *single* exceptional number that appears r times where
 *   r % 3 != 0 (not necessarily r == 1), and *all others* appear in multiples
 *   of 3, this method will still reconstruct the exceptional value's bits:
 *   count % 3 will be r at its 1-bits (non-zero), so we set those bits to 1.
 *
 * ----------------------------------------------------------------------
 * APPROACH 2: Bitmask "ones/twos" trick (k = 3, r = 1)
 *
 * STATE MACHINE IDEA:
 *   Maintain two bitmasks:
 *     - ones: bits seen (count % 3 == 1)
 *     - twos: bits seen (count % 3 == 2)
 *   When a bit arrives the third time, it should roll over back to 0.
 *
 *   Update rules on each x:
 *     ones = (ones ^ x) & ~twos;
 *     twos = (twos ^ x) & ~ones;   // uses updated 'ones'
 *
 * WHY IT'S NICE:
 *   - O(1) extra space.
 *   - Elegant, fast, and avoids an explicit 32-length array.
 *
 * WHEN IT WORKS:
 *   - Under the strict Single Number II promise: every other value appears
 *     exactly 3 times, and the unique appears exactly once. Then the final
 *     answer is in 'ones'.
 *
 * WHEN/WHY IT FAILS:
 *   - If the unique appears r != 1 times (e.g., 2 times), the final answer
 *     would reside in a different state variable (e.g., 'twos' holds it
 *     when r == 2). Our standard return 'ones' would be wrong.
 *   - If *any* other values appear counts not divisible by 3 (e.g., 2 times),
 *     they corrupt the modulo-3 state and the result is invalid.
 *
 * ----------------------------------------------------------------------
 * APPROACH 3: General k (bit counting modulo k)
 *
 * INTUITION:
 *   Same per-bit counting idea, but take counts modulo k. Reconstruct the
 *   result by setting a bit if (count % k != 0). This returns the "exceptional"
 *   number provided:
 *     - There is exactly one exceptional value that appears r times with
 *       r % k != 0, and
 *     - All other values appear in exact multiples of k.
 *
 * WHEN IT WORKS:
 *   - Any k >= 2, with exactly one exceptional value whose frequency r satisfies
 *     r % k != 0, and everyone else has frequency multiple of k.
 *
 * WHEN IT FAILS:
 *   - If multiple distinct values are "exceptional" (not multiples of k), their
 *     bits mix modulo k and the answer is not recoverable by a single pass of
 *     mod-k counting.
 *   - If the exceptional's r % k == 0, it disappears modulo k.
 *
 * ----------------------------------------------------------------------
 * TESTS INCLUDED:
 *   T1: Valid k=3 (all others thrice, one appears once) — all three solutions.
 *   T2: Valid k=3 with a negative unique and other positives — Approach 1 & 2.
 *   T3: Invalid (has some numbers appearing twice) — to demonstrate failure.
 *   T4: Valid general k=4 — Approach 3 only (Approach 1/2 are for k=3).
 *
 **************************************************************/

/**************************************************************
 * Single Number Variants — Three Approaches + Detailed Intuition
 *
 * Problem Recap:
 *   - Array contains integers.
 *   - Every number appears k times, except one which appears once.
 *   - Find that unique number.
 *
 * Approaches:
 *   1) Bit counting (array of 32 counters) for k = 3
 *   2) Bitmask trick (ones/twos) for k = 3
 *   3) Generalized bit counting for arbitrary k
 *
 * Why they work / when they fail are explained in detail in comments.
 **************************************************************/

#include <bits/stdc++.h>
using namespace std;

static constexpr int BIT = 32;

/***--------------------------------------------------------------
 * Approach 1: Bit Counting (k = 3)
 *
 * Idea:
 *   - For each of 32 bits, count how many numbers have that bit set.
 *   - If all numbers appeared 3 times, each bit’s count would be
 *     a multiple of 3. The unique number contributes “+1” to some
 *     bit positions. So we take (count % 3).
 *   - Build result from those bits.
 *
 * Complexity:
 *   - Time: O(32 * n) = O(n)
 *   - Space: O(1)
 *
 * Works ONLY if every element appears exactly 3 times except one.
 * If frequency pattern changes, counts % 3 won’t isolate the unique.
 *--------------------------------------------------------------*/
int singleNumber_bitCount3(const vector<int>& nums) {
    int result = 0;

    for (int b = 0; b < BIT; ++b) {
        int cnt = 0;
        for (int x : nums) {
            if (x & (1 << b)) cnt++;
        }
        // Keep bit if count is not divisible by 3
        if (cnt % 3 != 0) {
            result |= (1 << b);
        }
    }
    return result; // works for both positive & negative (two's complement)
}

/***--------------------------------------------------------------
 * Approach 2: Bitmask "ones/twos" trick (k = 3, r = 1)
 *
 * Idea:
 *   - We want to count each bit mod 3, but in O(1) space.
 *   - Maintain two masks:
 *       ones → bits that have appeared once (so far)
 *       twos → bits that have appeared twice (so far)
 *
 *   For each number x:
 *     ones = (ones ^ x) & ~twos
 *       → toggle bits in ones, but clear any that are already in twos
 *     twos = (twos ^ x) & ~ones
 *       → toggle bits in twos, but clear any that are now in ones
 *
 *   This cycles each bit through states:
 *       00 → 01 → 10 → 00
 *   (mod 3 counter using only 2 bits of storage).
 *
 * At the end, "ones" stores exactly the unique element.
 *
 * Complexity:
 *   - Time: O(n)
 *   - Space: O(1)
 *
 * ⚠️ Important:
 *   - Only works for the special case "every element appears 3 times
 *     except one that appears once". If the frequency promise is
 *     broken, this state machine loses meaning.
 *--------------------------------------------------------------*/
int singleNumber_bitmask3(const vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int x : nums) {
        ones = (ones ^ x) & ~twos;
        twos = (twos ^ x) & ~ones;
    }
    return ones;
}

/***--------------------------------------------------------------
 * Approach 3: General k (bit counting modulo k)
 *
 * Idea:
 *   - Same as Approach 1, but generalized to any k ≥ 2.
 *   - For each bit, count its frequency across all numbers.
 *   - The unique element will cause (count % k != 0).
 *
 * Complexity:
 *   - Time: O(32 * n)
 *   - Space: O(1)
 *
 * Works for ANY k, not just 3.
 * But:
 *   - Still requires that exactly one number appears once and all
 *     others appear exactly k times. Otherwise it fails.
 *--------------------------------------------------------------*/
int singleNumber_k(const vector<int>& nums, int k) {
    if (k <= 1) throw invalid_argument("k must be >= 2");

    int result = 0;
    for (int b = 0; b < BIT; ++b) {
        int cnt = 0;
        for (int x : nums) {
            if (x & (1 << b)) cnt++;
        }
        if (cnt % k != 0) {
            result |= (1 << b);
        }
    }
    return result;
}

/***--------------------------------------------------------------
 * Utilities
 *--------------------------------------------------------------*/
template <typename T>
string vec_to_string(const vector<T>& v) {
    ostringstream oss;
    oss << "[ ";
    for (auto& x : v) oss << x << " ";
    oss << "]";
    return oss.str();
}

/***--------------------------------------------------------------
 * MAIN with test cases
 *--------------------------------------------------------------*/
int main() {
    // T1: Classic Single Number II (k=3)
    {
        vector<int> nums = {2, 2, 3, 2};
        cout << "T1 nums = " << vec_to_string(nums) << "\n";
        cout << "  bitCount3: " << singleNumber_bitCount3(nums) << "\n";
        cout << "  bitmask3 : " << singleNumber_bitmask3(nums)  << "\n";
        cout << "  general k=3: " << singleNumber_k(nums, 3)    << "\n";
        cout << "  Expected  : 3\n\n";
    }

    // T2: k=3, negative unique
    {
        vector<int> nums = {-2,-2,-2, 5,5,5, 9,9,9, -7};
        cout << "T2 nums = " << vec_to_string(nums) << "\n";
        cout << "  bitCount3: " << singleNumber_bitCount3(nums) << "\n";
        cout << "  bitmask3 : " << singleNumber_bitmask3(nums)  << "\n";
        cout << "  general k=3: " << singleNumber_k(nums, 3)    << "\n";
        cout << "  Expected  : -7\n\n";
    }

    // T3: Invalid case (violates k=3 promise)
    {
        vector<int> nums = {7,4,5,3,4,4,7,3}; // has 2x elements
        cout << "T3 nums = " << vec_to_string(nums) << "\n";
        cout << "  bitCount3: " << singleNumber_bitCount3(nums) << " (may be wrong)\n";
        cout << "  bitmask3 : " << singleNumber_bitmask3(nums)  << " (may be wrong)\n";
        cout << "  general k=3: " << singleNumber_k(nums, 3)    << " (may be wrong)\n";
        cout << "  Expected  : (undefined, constraints broken)\n\n";
    }

    // T4: General k=4
    {
        vector<int> nums = {6,6,6,6, -2,-2,-2,-2, -1};
        cout << "T4 nums = " << vec_to_string(nums) << "\n";
        cout << "  general k=4: " << singleNumber_k(nums, 4) << "\n";
        cout << "  Expected    : -1\n\n";
    }

    return 0;
}

