class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> left(n), right(n);

        left[0] = make_pair(nums[0], 0);
        for(int i = 1; i < n; i++)
            if(nums[i] >= left[i - 1].first) {
                left[i] = make_pair(nums[i], i);
            } else left[i] = left[i - 1];
        
        right[n-1] = make_pair(nums[n - 1], n - 1);
        for(int i = n - 2; i >= 0; i--)
            if(nums[i] <= right[i + 1].first) {
                right[i] = make_pair(nums[i], i);
            } else right[i] = right[i + 1];
        
        int sum = 0;
        for(int i = 1; i < n - 1; i++) {
            if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
                sum += 2;
            else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
                sum += 1;
            else sum += 0;
        }
        return sum;
    }
};