
+++
authors = ["grid47"]
title = "Leetcode 1876: Substrings of Size Three with Distinct Characters"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1876: Substrings of Size Three with Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int cnt = 0;
        for(int i = 2; i < s.size(); i++)
            if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;

            return cnt;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1876.md" >}}
---
{{< youtube QIyWjKNstAA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1877: Minimize Maximum Pair Sum in Array](https://grid47.xyz/posts/leetcode-1877-minimize-maximum-pair-sum-in-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}