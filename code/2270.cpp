class Solution {
public:
    int waysToSplitArray(vector<int>& in) {
        
        
        // partial_sum(nums.begin(), nums.end(), nums.begin());
        
        int n = in.size(), res = 0;

        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
        nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[n - 1] - nums[i]) res++;
        }
        
        return res;
    }
};