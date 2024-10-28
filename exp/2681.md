class Solution {
public:
    int sumOfPower(vector<int>& nums) {
                
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        long long res = 0, sum = 0, mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            res = (res + (sum + nums[i]) * nums[i] % mod * nums[i]) % mod;
            sum = (sum * 2 + nums[i]) % mod;
        }
        
        return res % mod;
        
    }
};