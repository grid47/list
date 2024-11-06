
+++
authors = ["Crafted by Me"]
title = "Leetcode 2500: Delete Greatest Value in Each Row"
date = "2024-11-01"
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


---
{{< youtube xWRu1KHVAIo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2501: Longest Square Streak in an Array](https://grid47.xyz/posts/leetcode_2501) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
