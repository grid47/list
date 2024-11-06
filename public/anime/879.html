class Solution {
public:
    int mod = (int) 1e9 + 7;
    int profitableSchemes(int n, int mnp, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(mnp + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int k = 0; k < profit.size(); k++) {
            int p = profit[k], g = group[k];
            for(int i = mnp; i >= 0; i--)
            for(int j= n - g; j >= 0; j--)
                dp[min(i + p, mnp)][j + g] = (dp[min(i + p, mnp)][j + g] + dp[i][j]) % mod;
        }
        int ret = 0;
        for(int x: dp[mnp]) ret = (ret + x) % mod;
        
        return ret;
        
    }
};