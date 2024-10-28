class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, need = nums[0] + 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            res += max(0, need - nums[i]);
            need = max(nums[i], need) + 1;
        }
        
        return res;
    }
};