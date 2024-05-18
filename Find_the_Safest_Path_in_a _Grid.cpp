class UnionFind{
    public:
        vector<int> parent;
        int count; //number of disjoint sets
        UnionFind(int n){
            count = n;
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        bool unite(int a, int b){
            int rootA = find(a), rootB = find(b);
            if(rootA == rootB) return false;
            parent[rootA] = rootB;
            --count;
            return true;
        }
        int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
};
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        if(grid[0][0] || grid[gridSize-1][gridSize-1]){
            return 0;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dist(gridSize,vector<int>(gridSize,INT_MAX));

       
        for(int i = 0; i < gridSize; i++){
            for(int j = 0; j < gridSize; j++){
                if(grid[i][j]){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
              
        int dirs[5] = {-1,0,1,0,-1};
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int x = i + dirs[k], y = j + dirs[k+1];
                if(x >= 0 && x < gridSize && y >= 0 && y < gridSize && dist[x][y] == INT_MAX){
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x,y});
                }
            }
        }

        vector<tuple<int,int,int>> distances;
        for(int i = 0; i < gridSize; i++){
            for(int j = 0; j < gridSize; j++){
                distances.push_back({dist[i][j],i,j});
            }
        }
       
        sort(distances.begin(),distances.end(),greater<>());
        UnionFind uf(gridSize * gridSize);
        for(auto [distance, i, j] : distances){
            for(int k = 0; k < 4; k++){
                int x = i + dirs[k], y = j + dirs[k+1];
                 if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && dist[x][y] >= distance) {
                    uf.unite(i*gridSize + j, x * gridSize + y);
                }
            }
            if(uf.find(0) == uf.find(gridSize * gridSize - 1))
                return distance;
        }
        return 0;

    }
};
