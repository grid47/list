class Solution {
    int mod = (int) 1e9 + 7;
public:
    int findPaths(int m, int n, int mv, int i, int j) {
        
        vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        
        return dfs(m, n, mv, 0, i, j, mm);
        
    }
    
    int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {

        if (x < 0 || y < 0 || x >= m || y >= n) return 1;
        if (mv == mx)                           return 0;
        if (mm[mv][x][y] > -1)                  return mm[mv][x][y];

        int res = 0;
        res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;

        return mm[mv][x][y] = (res % mod);
    }
};