
+++
authors = ["Crafted by Me"]
title = "Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length()); 
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1769.md" >}}
---
{{< youtube R8geTAz_yk8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1770: Maximum Score from Performing Multiplication Operations](https://grid47.xyz/posts/leetcode_1770) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
