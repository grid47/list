class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
        typedef long long ll;
        
        ll mod = 1e9 + 7;
        int n = nums.size();
        ll res = 0;
        sort(nums.begin(), nums.end());
        ll c = 1;
        for(int i = 0; i < n; i++, c = (c * 2)% mod)
        res = ((ll) nums[i] * c - (ll) nums[n - 1 - i] * c + res) % mod;

        return (int) res;
    }
};