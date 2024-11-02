
+++
authors = ["Crafted by Me"]
title = "Leetcode 2825: Make String a Subsequence Using Cyclic Increments"
date = "2017-02-07"
description = "Solution to Leetcode 2825"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0, n = s1.size(), m = s2.size();
        for (int i = 0; i < n && j < m; ++i)
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
                ++j;
        return j == m;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

