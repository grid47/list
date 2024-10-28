class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
        // return b[2] < a[2];
    }
    
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int j = index[i];
            for(int k = n - 1; k > j; k--)
                ans[k] = ans[k - 1];
            ans[j] = nums[i];
        }
        return ans;
    }
};