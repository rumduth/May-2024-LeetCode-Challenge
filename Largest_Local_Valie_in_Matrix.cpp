/*
You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid
centered around row i + 1 and column j + 1. In other words, we want to find the
largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.
*/
class Solution {
public:
  int maxVal(int i, int j, vector<vector<int>> &grid) {
    int maxVal = grid[i][j];
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, 0},
                                  {1, -1},  {0, 1},  {0, 0},  {0, -1}};
    for (auto &p : dir) {
      maxVal = max(maxVal, grid[i + p.first][j + p.second]);
    }
    return maxVal;
  }
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        int grid_i = i + 1;
        int grid_j = j + 1;
        ans[i][j] = maxVal(grid_i, grid_j, grid);
      }
    }
    return ans;
  }
};