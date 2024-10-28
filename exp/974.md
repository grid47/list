class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), sum = 0;        
        vector<int> frq(k, 0);
        frq[0] = 1;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            int rm = sum % k;
            if(rm < 0) rm += k;            
            res += frq[rm];
            frq[rm]++;
        }
        return res;
    }
};