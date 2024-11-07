
+++
authors = ["Crafted by Me"]
title = "Leetcode 2732: Find a Good Subset of the Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2732: Find a Good Subset of the Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Matrix"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-a-good-subset-of-the-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    const int N = 1 << grid[0].size();
    vector<int> first_index(N, -1);
    for (int i = grid.size() - 1; i >=0; --i) {
      first_index[Encode(grid[i])] = i;
    }
    if (first_index[0] != -1) {
      return {first_index[0]};
    }

    for (int a = 1; a < N; ++a) {
      if (first_index[a] == -1) continue;
      for (int b = a + 1; b < N; ++b) {
        if (first_index[b] == -1) continue;
        if ((a & b) == 0) {
          int ra = first_index[a];
          int rb = first_index[b];
          return {min(ra, rb), max(ra, rb)};
        }
      }
    }
    return {};
  }
  
  static uint Encode(const vector<int>& row) {
    uint x = 0;
    for (int i = 0; i < row.size(); ++i) {
      if (row[i] == 0) continue;
      x |= 1 << i;
    }
    return x;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2732.md" >}}
---
{{< youtube 3NB86-4aEkI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2733: Neither Minimum nor Maximum](https://grid47.xyz/posts/leetcode_2733) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
