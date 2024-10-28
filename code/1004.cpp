class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            while(cnt[0] > k && j <= i) {
                cnt[nums[j]]--;
                j++;
            }
            res = max(res, (i - j + 1));
        }
        return res;
    }
};