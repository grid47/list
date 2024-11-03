
+++
authors = ["Crafted by Me"]
title = "Leetcode 2432: The Employee That Worked on the Longest Task"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2432: The Employee That Worked on the Longest Task in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---
{{< youtube BxVwXRLZlhk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2433: Find The Original Array of Prefix Xor](https://grid47.xyz/posts/leetcode_2433) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

