class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s;
    int res = INT_MAX;
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it));
        if (it != end(s))
            res = min(res, *it - nums[i]);
    }
        return res;
    }
};