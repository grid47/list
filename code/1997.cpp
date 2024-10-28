class Solution {
public:
    int n;
    
    int firstDayBeenInAllRooms(vector<int>& nxt) {
        n = nxt.size();
        int mod = (int) 1e9 + 7;
        vector<long long> dp(n, 0); // step
        for(int i = 1; i < n; i++)
            dp[i] = (dp[i - 1] + 1 + (dp[i - 1] - dp[nxt[i - 1]]) + 1 + mod) % mod;
        
        return dp[n - 1];
    }
};