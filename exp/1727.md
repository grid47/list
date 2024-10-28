class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mtx) {
        int n = mtx[0].size(), m = mtx.size();
        vector<vector<int>> one(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if (mtx[j][i] == 1) { cnt++; } 
                else { cnt = 0; }
                one[j][i] = cnt;
            }
        }
        
        for(int i = 0; i < m; i++)
        sort(one[i].rbegin(), one[i].rend());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                res = max(res, one[i][j] * (j + 1));
                
            }
        }
        return res;
    }
};