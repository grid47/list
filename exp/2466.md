class Solution {
    int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans = (ans + score(i, dp, zero, one)) % mod;
        }
        return ans;
    }

    int score(int target, vector<int> &dp, int zero, int one) {
        if(target == 0)      return 1;
        if(target < 1 )      return 0;
        if(dp[target] != -1) return dp[target];

        long long sum = score(target - zero, dp, zero, one) + score(target - one, dp, zero, one);

        return dp[target] = sum % mod;
    }
};