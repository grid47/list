
+++
authors = ["Crafted by Me"]
title = "Leetcode 400: Nth Digit"
date = "2022-09-28"
description = "Solution to Leetcode 400"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/nth-digit/description/)

---

**Code:**

{{< highlight cpp >}}
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;
        lli cnt = 9;
        lli start = 1;
        while(n > len * cnt) {

            n -= len * cnt;
            
            len++;
            cnt *= 10;
            start *= 10;

        }
        start += (n - 1) / len;
        string s = to_string(start);     
        return s[(n - 1) % len] - '0';
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/400.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

