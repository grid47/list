class Solution {
public:
    int memo[5001][2][2];
    vector<int> nums;
    int dp(int idx, bool buy, bool cool) {
        if(idx == nums.size()) return 0;
        
        if(memo[idx][buy][cool] != -1) return memo[idx][buy][cool];
        
        int res = dp(idx + 1, buy, false);
        if(buy && !cool) {
            res = max(res, dp(idx + 1, false, false) - nums[idx]);
        } else if(!buy) {
            res = max(res, dp(idx + 1, true, true) + nums[idx]);
        }
        return memo[idx][buy][cool] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        this->nums = prices;
        return dp(0, true, false);
    }
};