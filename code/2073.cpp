class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int res = 0, key = nums[k];
        for(int i = 0; i < nums.size(); i++) {
          res += min(key - (i > k), nums[i]);
        }
        return res;
    }
};