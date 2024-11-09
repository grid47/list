
+++
authors = ["grid47"]
title = "Leetcode 2374: Node With Highest Edge Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2374: Node With Highest Edge Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/node-with-highest-edge-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, long long> mp;
        int n = edges.size();
        int mx = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            mp[edges[i]] += i;
            if(mp[edges[i]] > mx) {
                idx = edges[i];
                mx = mp[edges[i]];
            } else if(mp[edges[i]] == mx) {
                if(edges[i] < idx)
                    idx = edges[i];
            }
        }
        return idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2374.md" >}}
---
{{< youtube 1egOQhIT9Gg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2375: Construct Smallest Number From DI String](https://grid47.xyz/posts/leetcode-2374-node-with-highest-edge-score-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
