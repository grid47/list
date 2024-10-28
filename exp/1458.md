class Solution {
public:
    
    vector<vector<int>> dp;
    vector<int> n1, n2;
    
    int dot(int i, int j) {

        if(i == n1.size() || j == n2.size()) return INT_MIN;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = dot(i + 1, j);
            ans = max(ans, dot(i, j + 1));
            ans = max(ans, n1[i] * n2[j]);
        
        long q = (long) n1[i] * n2[j] + dot(i + 1, j + 1);
        if(q <= INT_MAX && q >= INT_MIN)
        ans = max(ans, (int) q);

        return dp[i][j] = ans;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        
        n1 = nums1;
        n2 = nums2;
        
        return dot(0, 0);
    }
};