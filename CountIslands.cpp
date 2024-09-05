/*****************************************************************************************
Count the number of islands in a binary grid.
Example:
Input: grid = [["1", "0", "0", "1"], ["1", "0", "1", "0"], ["0", "0",
"1", "1"]]
Output: 3
Explanation:
Three separate islands in the grid
*****************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {{'1', '0', '0', '1'}, {'1', '0', '1', '0'}, {'0', '0', '1', '1'}};
    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}

