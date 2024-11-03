
+++
authors = ["Crafted by Me"]
title = "Leetcode 2144: Minimum Cost of Buying Candies With Discount"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2144: Minimum Cost of Buying Candies With Discount in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---
{{< youtube KvdPgFfH1t0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2145: Count the Hidden Sequences](https://grid47.xyz/posts/leetcode_2145) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

