#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int m, int n, int i, int j) {
    visited[i][j] = 1;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && board[nx][ny] == 'O')
                dfs(board, visited, m, n, nx, ny);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    // Mark all 'O's connected to borders
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O' && !visited[i][0])
            dfs(board, visited, m, n, i, 0);
        if (board[i][n - 1] == 'O' && !visited[i][n - 1])
            dfs(board, visited, m, n, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O' && !visited[0][j])
            dfs(board, visited, m, n, 0, j);
        if (board[m - 1][j] == 'O' && !visited[m - 1][j])
            dfs(board, visited, m, n, m - 1, j);
    }

    // Flip all unvisited 'O's to 'X'
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
        }
    }
}

void printBoard(const vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

int main() {
    // Test case 1: Basic surrounded region
    vector<vector<char>> board1 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    cout << "Before:\n"; printBoard(board1);
    solve(board1);
    cout << "After:\n"; printBoard(board1);
    // Expected:
    // X X X X
    // X X X X
    // X X X X
    // X O X X

    cout << endl;

    // Test case 2: No surrounded 'O'
    vector<vector<char>> board2 = {
        {'O','O','O'},
        {'O','X','O'},
        {'O','O','O'}
    };
    cout << "Before:\n"; printBoard(board2);
    solve(board2);
    cout << "After:\n"; printBoard(board2);
    // Expected: no change (all border-connected)

    cout << endl;

    // Test case 3: All 'X'
    vector<vector<char>> board3 = {
        {'X','X','X'},
        {'X','X','X'}
    };
    cout << "Before:\n"; printBoard(board3);
    solve(board3);
    cout << "After:\n"; printBoard(board3);
    // Expected: no change

    return 0;
}
