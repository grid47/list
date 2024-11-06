
+++
authors = ["Crafted by Me"]
title = "Leetcode 833: Find And Replace in String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 833: Find And Replace in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-and-replace-in-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        /*
        
        string s
        indices - arr of int
        src       arr of str
        tgt       arr of str
        
        */
        
        vector<pair<int, int>> ind;
        
        for(int i = 0; i < indices.size(); i++)
            ind.push_back({indices[i], i});
        
        sort(ind.rbegin(), ind.rend());
        
        for(auto it: ind) {
            string src = sources[it.second], tgt = targets[it.second];
            if(s.substr(it.first, src.size()) == src)
                s = s.substr(0, it.first) + tgt + s.substr(it.first+ src.size());
        }
        
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/833.md" >}}
---
{{< youtube J6Gtc4haYHg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #834: Sum of Distances in Tree](https://grid47.xyz/posts/leetcode_834) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

