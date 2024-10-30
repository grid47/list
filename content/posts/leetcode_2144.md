
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2144: Minimum Cost of Buying Candies With Discount"
date = "2018-12-18"
description = "Solution to Leetcode 2144"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

