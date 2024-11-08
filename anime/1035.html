class Solution {
public:
    int m, n;
    vector<int> nums1, nums2;
    vector<vector<int>> memo;

    int dp(int i, int j) {
        if(i == m || j == n) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = INT_MIN;
        if(nums1[i] == nums2[j]) {
            ans = 1 + dp(i + 1, j + 1);
            return ans;
        }
        ans = max(dp(i + 1, j), dp(i, j + 1));
        return memo[i][j] = ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums1.size(), n = nums2.size();
        memo.resize(m+1, vector<int>(n+1, -1));
        
        return dp(0, 0);
    }
};