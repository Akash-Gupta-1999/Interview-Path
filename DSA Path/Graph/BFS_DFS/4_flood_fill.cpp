#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>> q;
    int p_col = image[sr][sc];
    if (p_col == color) return image; // no change needed

    int m = image.size(), n = image[0].size();
    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, -1, 1, 0};

    image[sr][sc] = color;
    q.push({sr, sc});

    while (!q.empty()) {
        auto coord = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x_c = coord.first + x[i];
            int y_c = coord.second + y[i];
            if (x_c >= 0 && x_c < m && y_c >= 0 && y_c < n && image[x_c][y_c] == p_col) {
                image[x_c][y_c] = color;
                q.push({x_c, y_c});
            }
        }
    }
    return image;
}

void printImage(const vector<vector<int>>& image) {
    for (auto& row : image) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }
    cout << "----" << endl;
}

int main() {
    // Test case 1
    vector<vector<int>> image1 = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    auto res1 = floodFill(image1, 1, 1, 2);
    cout << "Test Case 1:" << endl;
    printImage(res1);
    // Expected:
    // 2 2 2
    // 2 2 0
    // 2 0 1

    // Test case 2
    vector<vector<int>> image2 = {
        {0,0,0},
        {0,0,0}
    };
    auto res2 = floodFill(image2, 0, 0, 0);
    cout << "Test Case 2:" << endl;
    printImage(res2);
    // Expected: unchanged (all 0s)

    // Test case 3
    vector<vector<int>> image3 = {
        {0,0,0},
        {0,1,1}
    };
    auto res3 = floodFill(image3, 1, 1, 1);
    cout << "Test Case 3:" << endl;
    printImage(res3);
    // Expected: unchanged (new color = old color)

    // Test case 4
    vector<vector<int>> image4 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    auto res4 = floodFill(image4, 0, 0, 5);
    cout << "Test Case 4:" << endl;
    printImage(res4);
    // Expected: entire grid becomes 5

    return 0;
}
