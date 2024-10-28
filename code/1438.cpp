class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[j++]));
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};