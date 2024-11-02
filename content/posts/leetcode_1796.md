
+++
authors = ["Crafted by Me"]
title = "Leetcode 1796: Second Largest Digit in a String"
date = "2018-12-02"
description = "Solution to Leetcode 1796"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/second-largest-digit-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int secondHighest(string s) {
        // support variables
        int res[2] = {-1, -1};
        // parsing s
        for (char c: s) {
            // considering only numerical characters
            if (c >= '0' && c <= '9') {
                // normalising c
                c -= '0';
                // updating res
                if (c > res[0]) {
                    res[1] = res[0];
                    res[0] = c;
                } else if (c != res[0] && c > res[1]) res[1] = c;
            }
        }
        return res[1];
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

