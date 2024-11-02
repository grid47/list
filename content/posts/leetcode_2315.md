
+++
authors = ["Crafted by Me"]
title = "Leetcode 2315: Count Asterisks"
date = "2017-07-01"
description = "Solution to Leetcode 2315"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-asterisks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countAsterisks(string s) {
        int res = 0, sign = 1;
        for (char& c : s)
            if ((sign ^= c == '|') && c == '*')
                res++;
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

