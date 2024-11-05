
+++
authors = ["Crafted by Me"]
title = "Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSteps(string s) {
        
        int idx = s.size() - 1, cnt = 0;
        
        while(idx > 0) {
            if(s[idx] == '0') {
                cnt++;
                idx--;
            } else {
                int tmp = idx;
                while(idx >= 0 && s[idx] == '1') idx--;
                cnt++; // add one
                if(idx >= 0) {
                    s[idx] = '1';
                    cnt += (tmp-idx); // divide by 2
                } else {
                    cnt += (tmp-idx);
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1404.md" >}}
---
{{< youtube qxt7_HD8Cag >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1405: Longest Happy String](https://grid47.xyz/posts/leetcode_1405) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

