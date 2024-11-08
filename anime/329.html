class Solution {
public:
    int m, n;
    vector<vector<int>> mtx, vis, memo;
    int dfs(int i, int j) {
        if(memo[i][j] != -1) return memo[i][j];
        int res = 1;
        vis[i][j] = 1;
        
    if(i > 0 && !vis[i - 1][j] && mtx[i - 1][j] > mtx[i][j]) res = max(res, 1 + dfs(i - 1, j));
    if(j > 0 && !vis[i][j - 1] && mtx[i][j - 1] > mtx[i][j]) res = max(res, 1 + dfs(i, j - 1));
if(i < m - 1 && !vis[i + 1][j] && mtx[i + 1][j] > mtx[i][j]) res = max(res, 1 + dfs(i + 1, j));
if(j < n - 1 && !vis[i][j + 1] && mtx[i][j + 1] > mtx[i][j]) res = max(res, 1 + dfs(i, j + 1));        
        vis[i][j] = 0;
        return memo[i][j] = res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mtx) {
        this->m = mtx.size();
        this->n = mtx[0].size();
        this->mtx = mtx;

            memo.resize(m, vector<int>(n, -1));        
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            vis.resize(m, vector<int>(n, 0));
            res = max(res, dfs(i, j));
        }
        return res;
    }
};