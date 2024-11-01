
+++
authors = ["Crafted by Me"]
title = "Leetcode 2269: Find the K-Beauty of a Number"
date = "2018-08-17"
description = "Solution to Leetcode 2269"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0, cur = 0, pow = 1;
        for (int n = num; n > 0; n /= 10) {
            cur += (n % 10) * pow;
            if (--k > 0)
                pow *= 10;
            else {
                res += cur && !(num % cur);
                cur /= 10;
            }
        }
        return res;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

