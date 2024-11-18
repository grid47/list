
+++
authors = ["grid47"]
title = "Leetcode 198: House Robber"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 198: House Robber in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "UVNgW5nSoiU"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp"
+++



[`Problem Link`](https://leetcode.com/problems/house-robber/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp" 
    alt="A series of houses softly glowing, with the optimal path for robbing illuminating."
    caption="Solution to LeetCode 198: House Robber Problem"
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
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> dp(n,0);
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-2]+a[i], dp[i-1]);
        return dp[n-1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/198.md" >}}
---
{{< youtube UVNgW5nSoiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #199: Binary Tree Right Side View](https://grid47.xyz/leetcode/solution-199-binary-tree-right-side-view/) |
| --- |
