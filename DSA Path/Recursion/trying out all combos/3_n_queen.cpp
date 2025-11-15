#include <bits/stdc++.h>
using namespace std;

/*
===================================================================
  EXPLANATION OF HASHING IN N-QUEENS (with Diagonal Mapping)
===================================================================

We want to place N queens on an N×N board so that no two queens 
attack each other. That means:
  1. No two queens share the same row
  2. No two queens share the same column
  3. No two queens share the same diagonal (both left and right)

Instead of checking the whole board every time (O(N) per check),
we can store "attack status" in three boolean/hash arrays:
  colcheck[col]        → Marks if a column has a queen
  leftdiag[row+col]    → Marks if a LEFT-to-RIGHT '\' diagonal has a queen
  rightdiag[n-1+col-row] → Marks if a RIGHT-to-LEFT '/' diagonal has a queen

-------------------------------------------------------------------
  HOW DIAGONAL INDEXING WORKS
-------------------------------------------------------------------

Example for N = 4 board:

    Coordinates: (row, col)
    LEFT DIAGONALS (\):
      Formula: row + col
      All cells with the same row+col are on the same '\' diagonal.

      Board with "row+col" values:
        0   1   2   3
        1   2   3   4
        2   3   4   5
        3   4   5   6

    RIGHT DIAGONALS (/):
      Formula: (n - 1) + (col - row)
      All cells with the same (n-1 + col - row) are on the same '/' diagonal.

      Board with "n-1+col-row" values (n=4, n-1=3):
        3   4   5   6
        2   3   4   5
        1   2   3   4
        0   1   2   3

So, by indexing diagonals this way, we can check 
if a queen is already attacking in O(1) time.
*/

/* =========================================================
   METHOD 1: Naive Approach (check each time)
   ---------------------------------------------------------
   Time Complexity:
       - Each placement requires checking up to O(N) cells 
         in column and diagonals → O(N) per placement.
       - There are N! possible permutations in worst case.
       - Total: O(N!) * O(N) ≈ O(N^(N+1)) in worst case.
   Space Complexity:
       - Board: O(N^2)
       - Recursion depth: O(N)
       - Total: O(N^2)
========================================================= */
bool ispossible(int row, int col, vector<string>& board, int n) {
    int duprow = row, dupcol = col;
    // Check upper left diagonal
    while (duprow >= 0 && dupcol >= 0) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow--;
        dupcol--;
    }
    duprow = row;
    dupcol = col;
    // Check same column upwards
    while (duprow >= 0) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow--;
    }
    duprow = row;
    dupcol = col;
    // Check upper right diagonal
    while (duprow >= 0 && dupcol < n) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow--;
        dupcol++;
    }
    return true;
}

void rec_solve_naive(int row, vector<string>& board, vector<vector<string>>& res, int n) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (ispossible(row, col, board, n)) {
            board[row][col] = 'Q';
            rec_solve_naive(row + 1, board, res, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens_naive(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    rec_solve_naive(0, board, res, n);
    return res;
}

/* =========================================================
   METHOD 2: Optimized Hashing Approach
   ---------------------------------------------------------
   Time Complexity:
       - We do O(1) checks using hash arrays instead of O(N).
       - Still explore up to N! permutations in worst case.
       - Total: O(N!) (much faster in practice due to pruning).
   Space Complexity:
       - Board: O(N^2)
       - Hash arrays: O(5N) ≈ O(N)
       - Recursion depth: O(N)
       - Total: O(N^2)
========================================================= */
void rec_solve_hash(int row, vector<string>& board,
                    vector<int>& colcheck, vector<int>& leftdiag, vector<int>& rightdiag,
                    vector<vector<string>>& res, int n) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (colcheck[col] == 0 && leftdiag[row + col] == 0 && rightdiag[n - 1 + col - row] == 0) {
            colcheck[col] = 1;
            leftdiag[row + col] = 1;
            rightdiag[n - 1 + col - row] = 1;
            board[row][col] = 'Q';

            rec_solve_hash(row + 1, board, colcheck, leftdiag, rightdiag, res, n);

            // Backtrack
            colcheck[col] = 0;
            leftdiag[row + col] = 0;
            rightdiag[n - 1 + col - row] = 0;
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens_hash(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    vector<int> colcheck(n, 0), leftdiag(2 * n - 1, 0), rightdiag(2 * n - 1, 0);
    rec_solve_hash(0, board, colcheck, leftdiag, rightdiag, res, n);
    return res;
}

// =====================
// MAIN + Test Cases
// =====================
int main() {
    int n = 4;

    cout << "=== METHOD 1: Naive Checking ===\n";
    vector<vector<string>> res1 = solveNQueens_naive(n);
    for (auto& board : res1) {
        for (auto& row : board) cout << row << "\n";
        cout << "\n";
    }
    cout << "Total Solutions: " << res1.size() << "\n\n";

    cout << "=== METHOD 2: Optimized Hashing ===\n";
    vector<vector<string>> res2 = solveNQueens_hash(n);
    for (auto& board : res2) {
        for (auto& row : board) cout << row << "\n";
        cout << "\n";
    }
    cout << "Total Solutions: " << res2.size() << "\n";

    return 0;
}
