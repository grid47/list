class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        int res = nums[0];
        for(int i = 0; i < n; i++) {
            nums[i] += q.size() ? q.front() : 0;
            res = max(res, nums[i]);
            while(q.size() > 0 && nums[i] > q.back()) {
                q.pop_back();
            }
            if(nums[i] > 0) {
                q.push_back(nums[i]);
            }
            if(i >= k && q.size() && q.front() == nums[i - k]) {
                q.pop_front();
            }
        }
        return res;
    }
};