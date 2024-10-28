class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        long long res = 0;
        vector<long long> cnt(n, 0);
        for(auto& r: req) {
            cnt[r[0]]++;
            if(r[1] + 1 < n)
                cnt[r[1] +1]--;
    }
        
        for(int i = 1; i < n; i++)
            cnt[i] += cnt[i -1];
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++)
            res +=  ((long long) nums[i] * cnt[i]);
        
        return res % 1000000007;
        }
};