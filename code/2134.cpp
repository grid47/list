class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
        ones = count(nums.begin(), nums.end(), 1);
        vector<int> nums2(2 *n);
        for(int i = 0; i < 2 * n; i++)
        nums2[i] = nums[i%n];
        for(int i = 0; i < 2 *n ; i++) {
            if(i >= ones && nums2[i - ones] == 1) x--;
            if(nums2[i] == 1) x++;
            onesInWindows = max(x, onesInWindows);
        }
        return ones - onesInWindows;
    }
};