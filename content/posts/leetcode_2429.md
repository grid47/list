
+++
authors = ["Crafted by Me"]
title = "Leetcode 2429: Minimize XOR"
date = "2018-03-10"
description = "In-depth solution and explanation for Leetcode 2429: Minimize XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-xor/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            if(((num1 >> i) & 1) == 1) {
                if(n > 0) {
                    res |= (1 << i);
                    n--;
                    if(n == 0) return res;
                }
            }
        }
        int i = 0;
        while(n > 0) {
            if(((res >> i) & 1) == 0) {
                res |= (1 << i);
                n--;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}


---


"| 2430: Maximum Deletions on a String |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

