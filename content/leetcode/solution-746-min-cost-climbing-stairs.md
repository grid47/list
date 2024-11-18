
+++
authors = ["grid47"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 746: Min Cost Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/746.webp"
youtube = "fPnQWeFlBCU"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/fPnQWeFlBCU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/min-cost-climbing-stairs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/746.webp" 
    alt="A staircase where the minimum cost to climb is calculated, with each step glowing softly as it is taken."
    caption="Solution to LeetCode 746: Min Cost Climbing Stairs Problem"
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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        
        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/746.md" >}}
---
{{< youtube fPnQWeFlBCU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #752: Open the Lock](https://grid47.xyz/leetcode/solution-752-open-the-lock/) |
| --- |
