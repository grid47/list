
+++
authors = ["grid47"]
title = "Leetcode 1054: Distant Barcodes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1054: Distant Barcodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distant-barcodes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        for(int num: b) mp[num]++;
        for(auto it: mp) st.insert({ it.second, it.first });
        for(auto it = st.rbegin(); it != st.rend(); it++) {
            for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
                if(pos >= b.size()) pos  = 1;
                b[pos] = it->second;
            }
        }
        return b;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1054.md" >}}
---
{{< youtube MlgCCJ7MfKQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1061: Lexicographically Smallest Equivalent String](https://grid47.xyz/posts/leetcode-1054-distant-barcodes-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
