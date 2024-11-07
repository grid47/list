
+++
authors = ["Crafted by Me"]
title = "Leetcode 765: Couples Holding Hands"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 765: Couples Holding Hands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Greedy","Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/couples-holding-hands/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size();
        
        vector<int> pos(n, 0);
        vector<int> ptn(n, 0);
        
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
            ptn[i] = (i % 2 == 0) ? i + 1 : i - 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = ptn[pos[ptn[row[i]]]]; j != i; j = ptn[pos[ptn[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/765.md" >}}
---
{{< youtube U0f5rx6CVNk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #767: Reorganize String](https://grid47.xyz/posts/leetcode_767) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
