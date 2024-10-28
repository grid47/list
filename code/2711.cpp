class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        set<int> ls, rs;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            int r = i - 1, c = j - 1;
            
            while(r >= 0 && c >= 0) {
                ls.insert(grid[r][c]);
                r--;
                c--;
            }
            
            r = i + 1, c = j + 1;
            
            while(r < m && c < n) {
                rs.insert(grid[r][c]);
                r++;
                c++;
            }
            int res = ls.size() - rs.size();
            ans[i][j] = abs(res);
            ls.clear();
            rs.clear();
        }
        return ans;
    }
};