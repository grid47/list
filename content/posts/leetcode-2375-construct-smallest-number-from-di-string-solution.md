
+++
authors = ["grid47"]
title = "Leetcode 2375: Construct Smallest Number From DI String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2375: Construct Smallest Number From DI String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-smallest-number-from-di-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestNumber(string ptn) {
        string res, stk;
        int n = ptn.size();
        for(int i = 0; i <= n; i++) {
            stk.push_back(i + '1');
            if(i == n || ptn[i] == 'I') {
                while(!stk.empty()) {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2375.md" >}}
---
{{< youtube b-vIB0xikOw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2379: Minimum Recolors to Get K Consecutive Black Blocks](https://grid47.xyz/posts/leetcode-2379-minimum-recolors-to-get-k-consecutive-black-blocks-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}