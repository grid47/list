
+++
authors = ["grid47"]
title = "Leetcode 2513: Minimize the Maximum of Two Arrays"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2513: Minimize the Maximum of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
        long long a = mx / div1;
        long long a_ = mx - a;
        long long b = mx / div2;
        long long b_ = mx - b;
        long long aib = mx / (long long)lcm(div1, div2);
        long long aub = a + b - aib;
        long long a_ib_ = mx - aub;
        long long neededA = (a_ - a_ib_ >= unq1) ? 0: unq1 - (a_ - a_ib_);
        long long neededB = (b_ - a_ib_ >= unq2) ? 0: unq2 - (b_ - a_ib_);        
        
        return a_ib_ >= neededA + neededB;
    }
    
    int minimizeSet(int div1, int div2, int unq1, int unq2) {
        
        long long l = 1, r = (long long) pow(10, 17), ans = 1;
        
        
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if(isPossible(mid, div1, div2, unq1, unq2)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2513.md" >}}
---
{{< youtube g6L-jnW2n_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2515: Shortest Distance to Target String in a Circular Array](https://grid47.xyz/posts/leetcode-2515-shortest-distance-to-target-string-in-a-circular-array-solution/) |
| --- |
