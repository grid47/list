
+++
authors = ["grid47"]
title = "Leetcode 2500: Delete Greatest Value in Each Row"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2500: Delete Greatest Value in Each Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)","Matrix","Simulation"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2500.md" >}}
---
{{< youtube xWRu1KHVAIo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2501: Longest Square Streak in an Array](https://grid47.xyz/posts/leetcode-2501-longest-square-streak-in-an-array-solution/) |
| --- |
