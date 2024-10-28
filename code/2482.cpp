class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }

        vector<vector<int>> g(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            g[i][j] = 2 * row[i] + 2 * col[j] - m - n;
        }
        return g;
    }
};