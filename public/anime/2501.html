class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i= 0; i < n; i++) {
            long long tmp = (long long) nums[i] * nums[i];
            if(tmp > INT_MAX) break;
            auto it = lower_bound(nums.begin(), nums.end(), tmp);
            if(it == nums.end()) break;
            int pos = it - nums.begin();
            while(pos < n && nums[i] * nums[i] == nums[pos]) {
                    dp[pos] = max(dp[pos], 1 + dp[i]);                
                    mx = max(mx, dp[pos]);  
                    pos++;
            }
        }
        return mx == 1? -1: mx;
    }
};