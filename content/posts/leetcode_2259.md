
+++
authors = ["Crafted by Me"]
title = "Leetcode 2259: Remove Digit From Number to Maximize Result"
date = "2018-08-27"
description = "Solution to Leetcode 2259"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDigit(string n, char digit) {
        for (int i = 0; i < n.size() - 1; ++i)
            if (n[i] == digit && n[i + 1] > digit)
                return n.substr(0, i) + n.substr(i + 1);
        int last_d = n.rfind(digit);
        return n.substr(0, last_d) + n.substr(last_d + 1);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

