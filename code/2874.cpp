class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, n = nums.size();
        long maxa = 0, maxab = 0;
        for(int a: nums) {
            res = max(res, 1L * maxab * a);
            maxab = max(maxab, (long) maxa - a);
            maxa = max(maxa, (long)a);
        }
        return res;
    }
};