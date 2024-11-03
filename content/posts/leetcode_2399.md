
+++
authors = ["Crafted by Me"]
title = "Leetcode 2399: Check Distances Between Same Letters"
date = "2018-04-09"
description = "In-depth solution and explanation for Leetcode 2399: Check Distances Between Same Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 2400: Number of Ways to Reach a Position After Exactly k Steps |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

