class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // 1 1 1 2 3 3 5
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> pos;
        pos[-1] = -1;
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
            if(it == nums.end()) break;
            int idx = it - nums.begin();
            pos[i] = idx;
            if(idx == n - 1) break;
        }
        return pos.size() - 1;
    }
};