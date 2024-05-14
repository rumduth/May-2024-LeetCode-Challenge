class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int sum;
        function<void(int,int,int)> dfs = [&](int i, int j, int sum){
            if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0){
                ans = max(ans,sum);
                return;
            }
            sum += grid[i][j];
            int val = grid[i][j];
            grid[i][j] = 0;
            for(auto& d : dir){
                dfs(i+d.first,j+d.second,sum);
            }
            grid[i][j] = val;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    dfs(i, j,0);
                }
            }
        }
        return ans;
    }
};
