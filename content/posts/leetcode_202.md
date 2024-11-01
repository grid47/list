
+++
authors = ["Crafted by Me"]
title = "Leetcode 202: Happy Number"
date = "2024-04-14"
description = "Solution to Leetcode 202"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/happy-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sqr(int n) {
        int res = 0;
        while(n) {
            int tmp = n % 10;
            res += tmp * tmp;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sqr(slow);
            fast = sqr(sqr(fast));
        } while(slow != fast);
        return slow == 1;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/202.md" >}}
- by gpt
        
---
{{< youtube 4IroNy8fmNA >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

