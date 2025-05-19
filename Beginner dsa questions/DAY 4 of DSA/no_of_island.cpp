#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int row, int col) {
        if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] == 1 || grid[x][y] == '0') {
            return;
        }
        visited[x][y] = 1;

        DFS(grid, visited, x + 1, y, row, col); // Down
        DFS(grid, visited, x, y + 1, row, col); // Right
        DFS(grid, visited, x - 1, y, row, col); // Up
        DFS(grid, visited, x, y - 1, row, col); // Left
    }

    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        int NO_of_island = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] != 1) {
                    DFS(grid, visited, i, j, row, col);
                    NO_of_island++;
                }
            }
        }
        return NO_of_island;
    }
};

int main() {
    int row, col;
    cout << "Enter the number of rows and columns: ";
    cin >> row >> col;

    vector<vector<char>> grid(row, vector<char>(col));
    cout << "Enter the grid (rows of '0' and '1'): \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
