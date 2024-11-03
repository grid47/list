
+++
authors = ["Crafted by Me"]
title = "Leetcode 963: Minimum Area Rectangle II"
date = "2022-03-15"
description = "In-depth solution and explanation for Leetcode 963: Minimum Area Rectangle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-area-rectangle-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    size_t d2(int x1, int y1, int x2, int y2) {
      return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
      unordered_map<size_t, unordered_map<size_t, vector<vector<int>>>> m;
      for (auto i = 0; i < ps.size(); ++i)
        for (auto j = i + 1; j < ps.size(); ++j) {
          auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
          auto len = d2(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
          m[center][len].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
        }
      for (auto it_c = begin(m); it_c != end(m); ++it_c)
        for (auto it_l = begin(it_c->second); it_l != end(it_c->second); ++it_l)
          for (auto i = 0; i < it_l->second.size(); ++i)
            for (auto j = i + 1; j < it_l->second.size(); ++j) {
              auto &p1 = it_l->second[i], &p2 = it_l->second[j];
              auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
              if (res == 0 || res > area) res = area;
            }
      return sqrt(res);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/963.md" >}}
---


| Next : [LeetCode #964: Least Operators to Express Number](grid47.xyz/leetcode_964) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

