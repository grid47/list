
+++
authors = ["grid47"]
title = "Leetcode 718: Maximum Length of Repeated Subarray"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 718: Maximum Length of Repeated Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sliding Window","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/718.webp" 
    alt="An array where the longest repeated subarray is highlighted and softly glowing as it's determined."
    caption="Solution to LeetCode 718: Maximum Length of Repeated Subarray Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube MynhR1bMtWY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #720: Longest Word in Dictionary](https://grid47.xyz/leetcode/solution-720-longest-word-in-dictionary/) |
| --- |
