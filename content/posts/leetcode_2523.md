
+++
authors = ["Crafted by Me"]
title = "Leetcode 2523: Closest Prime Numbers in Range"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2523: Closest Prime Numbers in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool seive[1000001] = {};
    vector<int> p = {2};
    vector<int> closestPrimes(int left, int right) {
        
        for(int i = 3; i < 1000001; i += 2) {
            if(!seive[i]) {
                p.push_back(i);
                for (long long j = (long long) i * i; j < 1000001; j += i) {
                    seive[j] = true;
                }
            }
        }
        
        int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
        
        for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
            if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
                n1 = p[i];
                n2 = p[i + 1];
                if(n2 - n1 < 3) break;
            }
        }
        return {n1, n2};
    }
};
{{< /highlight >}}


---
{{< youtube HqSBI1RVM8c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2524: Maximum Frequency Score of a Subarray](https://grid47.xyz/posts/leetcode_2524) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
