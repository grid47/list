
+++
authors = ["Crafted by Me"]
title = "Leetcode 459: Repeated Substring Pattern"
date = "2022-07-31"
description = "Solution to Leetcode 459"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/repeated-substring-pattern/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/459.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

