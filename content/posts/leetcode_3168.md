
+++
authors = ["Crafted by Me"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2016-03-01"
description = "Solution to Leetcode 3168"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cnt = 0;
        for(char x: s) {
            cnt += (x == 'E'? 1: -1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

