class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<vector<int>> dp;

    int mem(int i, int j, vector<vector<int>> & grid) {
        long res = 1;
        if(dp[i][j] != -1) return dp[i][j];
        int dir[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if(x < 0 || y < 0 || x >= dp.size() || y >= dp[0].size() || grid[x][y] <= grid[i][j])
                continue;
            res = (res + mem(x, y, grid)) % mod;
        }
        return dp[i][j] = res % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        long res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            res = (res + mem(i, j, grid)) % mod;
        
        return res;
    }
};