class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> val(n + 1, 0);
        vector<int> dp (n + 1, 0);
        
        for(int num : nums)
          val[num] += num;
        
        dp[0] = 0;
        dp[1] = val[0];
        for(int i = 1; i < n; i++)
        dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
        
        return dp[n];
    }
};