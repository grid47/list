
+++
authors = ["Crafted by Me"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2018-10-15"
description = "Solution to Leetcode 1844"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-all-digits-with-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string replaceDigits(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
        return s;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

