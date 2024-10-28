class Solution {
public:
    int minimumSize(vector<int>& nums, int mxOps) {
        
        int l = 1, r = *max_element(nums.begin(), nums.end());
        // int total_bags = n + 2 * mxOps - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int a: nums)
                cnt += (a - 1) / mid;
            if(cnt <= mxOps)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};