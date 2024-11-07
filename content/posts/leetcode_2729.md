
+++
authors = ["Crafted by Me"]
title = "Leetcode 2729: Check if The Number is Fascinating"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2729: Check if The Number is Fascinating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-number-is-fascinating/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isFascinating(int n) {
        int n1 = 2 * n;
        int n2 = 3 * n;
        vector<bool> yes(10, false); 
        string s = to_string(n) + to_string(n1) + to_string(n2);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') return false;
            if(yes[s[i] - '0']) return false;
            yes[s[i] - '0'] = true;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2729.md" >}}
---
{{< youtube B1JUo4KREiU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2730: Find the Longest Semi-Repetitive Substring](https://grid47.xyz/posts/leetcode_2730) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
