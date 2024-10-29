
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2500: Delete Greatest Value in Each Row"
date = "2017-12-26"
description = "Solution to Leetcode 2500"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-greatest-value-in-each-row/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int deleteGreatestValue(vector<vector<int>>& g) {
      int res = 0, si = g.size(), sj = g[0].size();
      for (auto &r : g)
          sort(begin(r), end(r));
      for (int j = 0; j < sj; ++j) {
          int max_row = 0;
          for (int i = 0; i < si; ++i) 
              max_row = max(max_row, g[i][j]);
          res += max_row;
      }
      return res;
  }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

