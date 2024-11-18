
+++
authors = ["grid47"]
title = "Leetcode 300: Longest Increasing Subsequence"
date = "2024-10-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 300: Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "VZc93A5v1JI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-increasing-subsequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp" 
    alt="A series of numbers gently connecting to form the longest increasing subsequence, glowing brightly along the way."
    caption="Solution to LeetCode 300: Longest Increasing Subsequence Problem"
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/300.md" >}}
---
{{< youtube VZc93A5v1JI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #309: Best Time to Buy and Sell Stock with Cooldown](https://grid47.xyz/leetcode/solution-309-best-time-to-buy-and-sell-stock-with-cooldown/) |
| --- |
