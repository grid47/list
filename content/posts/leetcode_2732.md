
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2732: Find a Good Subset of the Matrix"
date = "2017-05-08"
description = "Solution to Leetcode 2732"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

