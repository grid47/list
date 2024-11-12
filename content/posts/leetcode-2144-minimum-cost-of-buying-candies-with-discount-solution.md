
+++
authors = ["grid47"]
title = "Leetcode 2144: Minimum Cost of Buying Candies With Discount"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2144: Minimum Cost of Buying Candies With Discount in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size(), res = 0;
        for(int i = 0; i < n; i++) {
          if(i % 3 == n % 3) continue;
          res += cost[i];
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2144.md" >}}
---
{{< youtube KvdPgFfH1t0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2145: Count the Hidden Sequences](https://grid47.xyz/posts/leetcode-2145-count-the-hidden-sequences-solution/) |
| --- |
