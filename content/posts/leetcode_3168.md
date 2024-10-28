
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2016-02-26"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

