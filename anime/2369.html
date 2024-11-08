class Solution {
public:
    int n;
    vector<int> nums, memo;
    
    bool dp(int idx) {
        if(idx == n) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
            if(dp(idx + 2)) return memo[idx] = true;
        }
        
        if(idx + 2 < n) {
            if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
                if(dp(idx + 3)) return memo[idx] = true;                
            }
            if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
                if(dp(idx + 3)) return memo[idx] =true;
            }
        }

        return memo[idx] = false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, -1);
        return dp(0);
    }
};