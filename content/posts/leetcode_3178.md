
+++
authors = ["Crafted by Me"]
title = "Leetcode 3178: Find the Child Who Has the Ball After K Seconds"
date = "2015-02-19"
description = "Solution to Leetcode 3178"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfChild(int n, int k) {
        int up = false, idx = 0;
        for(int i = 0; i < k; i++) {

            if (idx == n - 1 || idx == 0) up = !up;

            if (up) idx++;
            else    idx--;

        }
        return idx;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

