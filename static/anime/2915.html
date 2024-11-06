class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int sum) {
        int n = nums.size();
        // Create a 2D array to store the dynamic programming results.
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0; // Longest subsequence when the target sum is 0.

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                // Initially, set the result to be the same as the result for the previous element.
                dp[i][j] = dp[i - 1][j];

                // Check if the current element can contribute to the current sum.
                if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
                    dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);
            }
        }

        return dp[n][sum]; // Return the result for the entire array with the target sum.
    }
};