
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2432: The Employee That Worked on the Longest Task"
date = "2018-03-03"
description = "Solution to Leetcode 2432"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

