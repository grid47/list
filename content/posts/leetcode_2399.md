
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2399: Check Distances Between Same Letters"
date = "2018-04-05"
description = "Solution to Leetcode 2399"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-distances-between-same-letters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  bool checkDistances(string s, vector<int>& distance) {
    int pos[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        int n = s[i] - 'a';
        if (pos[n] > 0 && distance[n] != i - pos[n])
            return false;
        pos[n] = i + 1;
    }
    return true;
  }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

