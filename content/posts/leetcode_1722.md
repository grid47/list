
+++
authors = ["Crafted by Me"]
title = "Leetcode 1722: Minimize Hamming Distance After Swap Operations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1722: Minimize Hamming Distance After Swap Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> parent, rnk;
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& swp) {
        int n = src.size();
        parent.resize(n, 0);
        rnk.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(vector<int> s: swp) {
            int x = find(s[0]);
            int y = find(s[1]);
            if(rnk[x] < rnk[y]) {
                parent[x] = y;
                rnk[y]++;
            } else {
                parent[y] = x;
                rnk[x]++;                
            }
        }
        
        unordered_map<int, unordered_map<int, int>> mp;
        
        for(int i = 0; i < n; i++) {
            int p = find(i);
            auto &m = mp[p];
            m[src[i]]++;
        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int p = find(i);
            auto &m = mp[p];
            if((m[dst[i]]--) <= 0) {
                res += 1;
            }
        }
        
        return res;
        
    }
    
    int find(int x) {
        int y = parent[x];
        if(y != x) {
            parent[x] = find(y);
        }
        return parent[x];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1722.md" >}}
---
{{< youtube G1vTpGA9Gkc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1723: Find Minimum Time to Finish All Jobs](https://grid47.xyz/posts/leetcode_1723) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
