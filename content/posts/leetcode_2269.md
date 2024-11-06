
+++
authors = ["Crafted by Me"]
title = "Leetcode 2269: Find the K-Beauty of a Number"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2269: Find the K-Beauty of a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Sliding Window"]
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
{{< youtube 23-y60kKUdY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2270: Number of Ways to Split Array](https://grid47.xyz/posts/leetcode_2270) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
