class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int hit) {
        int m = mat.size(), n = mat[0].size();
        int res = 0, len = 1;
        vector<vector<int>> sum(m + 1, vector<int> (n + 1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
                if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                    res = len++;
            }
        }
        
        return res;
    }
};