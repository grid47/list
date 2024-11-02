
+++
authors = ["Crafted by Me"]
title = "Leetcode 258: Add Digits"
date = "2023-02-17"
description = "Solution to Leetcode 258"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while(num > 9) {
            while(num > 0) {
                res += num % 10;
                num /= 10;
            }
            
            num = res;
            res = 0;
        }
        return num;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/258.md" >}}
---
{{< youtube gPZvXaniFDQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

