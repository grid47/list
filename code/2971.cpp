class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        for(int i = n - 1; i >= 2; i--)
            if(nums[i] < sum[i - 1])
                return sum[i];
        return -1;
    }
};