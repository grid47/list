
+++
authors = ["Yasir"]
title = "Leetcode 390: Elimination Game"
date = "2023-10-03"
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

{{< highlight html >}}
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

