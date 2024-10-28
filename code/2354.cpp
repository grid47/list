class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<int> cnt;
        vector<int> arr;
        for(int i = 0; i < n; i++)
            if(cnt.count(nums[i])) continue;
            else {
                arr.push_back(__builtin_popcount(nums[i]));
                cnt.insert(nums[i]);
            }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] * 2 >= k) {
                
                ans += 2 * (arr.size() - (i + 1));
                ans++;

            } else {

                int x = k - arr[i];

                auto it = lower_bound(arr.begin(), arr.end(), x);
                if(it == arr.end()) continue;

                int y = arr.end() - it;
                ans += 2 * y;
            }
        }
        if(arr.back() * 2 >= k) ans++;
        return ans;
    }
};