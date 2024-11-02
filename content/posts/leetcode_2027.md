
+++
authors = ["Crafted by Me"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2018-04-15"
description = "Solution to Leetcode 2027"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')
                i++;
            else
                count++, i += 3;
        }
        return count;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

