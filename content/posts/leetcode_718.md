
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 718: Maximum Length of Repeated Subarray"
date = "2022-11-12"
description = "Solution to Leetcode 718"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

        for(int i = 0; i < n1 + 1; i++) dp[i][0] = 0;
        for(int i = 0; i < n2 + 1; i++) dp[0][i] = 0;
        // dp[0][0] = 0;

        // subseq - !subarr
        int mx = 0;
        for(int i = 1; i < n1 + 1; i++)
        for(int j = 1; j < n2 + 1; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                 dp[i][j] = dp[i - 1][j - 1] + 1;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/718.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

