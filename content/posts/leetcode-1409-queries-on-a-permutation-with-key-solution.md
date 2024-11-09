
+++
authors = ["grid47"]
title = "Leetcode 1409: Queries on a Permutation With Key"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1409: Queries on a Permutation With Key in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queries-on-a-permutation-with-key/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans;
        for(int i = 1; i <= m; i++)
            ans.push_back(i);
        map<int, int> mp;
        for(int i = 0; i < ans.size(); i++)
            mp[ans[i]] = i;
        
        vector<int> res;
        for(int i = 0; i < q.size(); i++) {
            int x = mp[q[i]];
            res.push_back(x);
            for(auto it: mp) {
                if(it.second < x)
                mp[it.first]++; // shit to right
            }
            mp[q[i]] = 0;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1409.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1410: HTML Entity Parser](https://grid47.xyz/posts/leetcode-1409-queries-on-a-permutation-with-key-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
