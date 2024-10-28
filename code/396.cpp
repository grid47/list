class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, fn = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            fn += i * nums[i];
        }

        long l = 1, r;
        long newfn = fn;

        while(l < n) {
            r = l + n - 1;
            long removed = (l - 1) *nums[l -1];
            long added = r * nums[r % n];

            newfn = newfn - removed + added - sum;

            fn = max(fn, newfn);
            l++;
        }
        return fn;
    }
};