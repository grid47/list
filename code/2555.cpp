class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        
        int n = pos.size(), res = 0;
        
        vector<int> dp(n + 1, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(pos[j] < pos[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1+ dp[j]);
        }
        
        
        return res;
    }
};