
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 390: Elimination Game"
date = "2023-10-05"
description = "Solution to Leetcode 390"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/elimination-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int rm = n;
        int step = 1;
        int head = 1;
        while(rm > 1) {
            if(left || rm % 2 == 1) {
                head += step;
            }
            rm /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

