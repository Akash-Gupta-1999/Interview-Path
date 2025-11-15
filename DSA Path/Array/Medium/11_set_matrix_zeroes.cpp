#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix[0].size(), m = matrix.size();
    bool col_0 = false;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if(j == 0) {
                    col_0 = true;
                } else {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0)
        for(int j = 0; j < n; j++)
            matrix[0][j] = 0;

    if(col_0)
        for(int i = 0; i < m; i++)
            matrix[i][0] = 0;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "\nMatrix After setZeroes:\n";
    printMatrix(matrix);

    return 0;
}
