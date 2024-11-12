
+++
authors = ["grid47"]
title = "Leetcode 2432: The Employee That Worked on the Longest Task"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2432: The Employee That Worked on the Longest Task in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
      int end = 0, id = 0, max_t = 0;
      for (auto &l : logs) {
          if (max_t <= l[1] - end) {
              id = max_t < l[1] - end ? l[0] : min(id, l[0]);
              max_t = l[1] - end;
          }
          end = l[1];
      }
      return id;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2432.md" >}}
---
{{< youtube BxVwXRLZlhk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2433: Find The Original Array of Prefix Xor](https://grid47.xyz/posts/leetcode-2433-find-the-original-array-of-prefix-xor-solution/) |
| --- |
