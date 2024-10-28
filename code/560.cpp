class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int res = 0;
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            if(mp.count(sum - k)) cnt += mp[sum - k];
            mp[sum] += 1;
        }

        return cnt;
    }
};