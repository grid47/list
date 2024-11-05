
+++
authors = ["Crafted by Me"]
title = "Leetcode 1432: Max Difference You Can Get From Changing an Integer"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1432: Max Difference You Can Get From Changing an Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int change(int num, int x, int y) {
        int tmp = 0, ten = 1;
        int digit;
        while(num) {
            digit = num % 10;
            if(digit == x) digit = y;
            tmp = ten * digit + tmp;
            num /= 10;
            ten *= 10;
        }
        return digit == 0? -1: tmp;
    }
    
    int maxDiff(int num) {
        int mn = num, mx = num;
        for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++) {
            if(i == j) continue;
            int ret = change(num, i, j);
            if(ret <= 0) continue;
            mn = min(mn, ret);
            mx = max(mx, ret);
        }
        cout << mx << " " << mn;
        return mx - mn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1432.md" >}}
---
{{< youtube sOnpt2zHWfQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1433: Check If a String Can Break Another String](https://grid47.xyz/posts/leetcode_1433) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

