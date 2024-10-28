class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                return { mp[nums[i]], i };
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};