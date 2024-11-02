
+++
authors = ["Crafted by Me"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2018-01-08"
description = "Solution to Leetcode 2124"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool checkString(string s) {
        return s.find("ba")==string::npos;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

