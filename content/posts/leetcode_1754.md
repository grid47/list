
+++
authors = ["Crafted by Me"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2019-01-13"
description = "Solution to Leetcode 1754"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-merge-of-two-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestMerge(string w1, string w2) {
        if (w1 == "" || w2 == "")
            return w1 + w2;
        else if (w1 < w2)
            return w2[0] + largestMerge(w1, w2.substr(1));
        else return w1[0] + largestMerge(w1.substr(1), w2);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

