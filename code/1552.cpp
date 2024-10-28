class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int l = 0;
        int r = pos[n - 1]-pos[0];
        while(l < r) {
            int mid = r - (r - l) / 2;
            if(isValid(pos, mid, m)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    bool isValid(vector<int> &nums, int mid, int cnt) {
        int res = 1, cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] - cur >= mid) {
                res++;
                cur = nums[i];
            }
        }
        return res >= cnt;
    }
};