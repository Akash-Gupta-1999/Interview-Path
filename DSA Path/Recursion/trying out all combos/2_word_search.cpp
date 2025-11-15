#include <bits/stdc++.h>
using namespace std;

bool rec_search(int idx, int i, int j,vector<vector<char>>& board, string& word){
    if(idx == word.size())
        return true;
    vector<int> x = {0,-1,1,0};
    vector<int> y = {-1,0,0,1};
    for(int k=0;k<x.size();k++){
        int x_i = i + x[k];
        int y_j = j + y[k];
        if(x_i >= 0 && y_j >= 0 && x_i < board.size() && y_j < board[0].size() && board[x_i][y_j] != '!' && board[x_i][y_j] == word[idx]){
            char c = board[x_i][y_j];
            board[x_i][y_j] = '!';
            if(rec_search(idx+1,x_i,y_j,board,word))
                return true;
            board[x_i][y_j] = c;
        }
    }
    return false;
}

bool exist(vector<vector<char>> board, string word) {
    for(int i=0;i<board.size();i++){
        for(int j = 0;j<board[0].size();j++){
            int idx = 0;
            if(board[i][j] == word[idx]){
                char c = board[i][j];
                board[i][j] = '!';
                if(rec_search(idx+1,i,j,board,word))
                    return true;
                board[i][j] = c;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    cout << exist(board, "ABCCED") << "\n"; // 1
    cout << exist(board, "SEE") << "\n";    // 1
    cout << exist(board, "ABCB") << "\n";   // 0
}
