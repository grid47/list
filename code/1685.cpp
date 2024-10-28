class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
        vector<int> ans(n, 0);
        ans[0] = z;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
        
        return ans;
    }
};