class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = LLONG_MIN;

        int n = nums.size();
        map<int, int> mp;
        vector<long long> pre;
        pre.push_back(0);
        for(int i = 0; i < n; i++) {
            pre.push_back(pre.back() + nums[i]);
            if(mp.count(nums[i] - k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] - k]]);
            if(mp.count(nums[i] + k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] + k]]);
            auto it = mp.find(nums[i]);
            if(it == mp.end() || pre[i] - pre[it->second] <= 0) mp[nums[i]] = i;
        }
        return ans == LLONG_MIN? 0: ans;
    }
};