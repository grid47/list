class Solution {
public:
    vector<vector<vector<int>>> memo;    
    vector<vector<int>> grid;
    int m, n, k;
    int mod = (int) 1e9 + 7;
    
    int dp(int i, int j, int sum) {
        
        if((i == (m - 1)) && (j == (n - 1))) return (sum % k) == 0;
        
        if(memo[i][j][sum] != -1) return memo[i][j][sum];
        
        long long ans = 0;
        if(i + 1 < m) ans += dp(i + 1, j, (sum + grid[i + 1][j]) % k);
        if(j + 1 < n) ans += dp(i, j + 1, (sum + grid[i][j + 1]) % k);        
        
        return memo[i][j][sum] = ans % mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        this->k = k;
        memo.resize(m, vector<vector<int>>(n, vector<int>(50, -1)));
        
        return dp(0, 0, grid[0][0] % k);
        
    }
};