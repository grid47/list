
+++
authors = ["grid47"]
title = "Leetcode 740: Delete and Earn"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 740: Delete and Earn in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "MnbTKT4-KLc"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp"
+++



[`Problem Link`](https://leetcode.com/problems/delete-and-earn/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp" 
    alt="A series of numbers where the optimal strategy to delete and earn is highlighted, glowing softly as the calculation is made"
    caption="Solution to LeetCode 740: Delete and Earn Problem"
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
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> val(n + 1, 0);
        vector<int> dp (n + 1, 0);
        
        for(int num : nums)
          val[num] += num;
        
        dp[0] = 0;
        dp[1] = val[0];
        for(int i = 1; i < n; i++)
        dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
        
        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/740.md" >}}
---
{{< youtube MnbTKT4-KLc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #743: Network Delay Time](https://grid47.xyz/leetcode/solution-743-network-delay-time/) |
| --- |
