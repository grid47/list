
+++
authors = ["Crafted by Me"]
title = "Leetcode 1051: Height Checker"
date = "2020-12-16"
description = "Solution to Leetcode 1051"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/height-checker/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int heightChecker(vector<int>& h) {

        auto m = max_element(h.begin(), h.end());

        vector<int> exp(*m + 1);

        for (int height : h) exp[height]++;

        int res = 0;

        for (int j = 1, i = 0; j < exp.size(); j++)
            while (exp[j]--) res += (h[i++] != j);

        return res;

    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

