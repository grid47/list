class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0), ans(n, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        for(int i = 0; i < n; i++) {
            ans[i] = abs(net - sum[i + 1] - sum[i]);
        }
        return ans;
    }
};