
+++
authors = ["Yasir"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2020-01-09"
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

{{< highlight html >}}
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

