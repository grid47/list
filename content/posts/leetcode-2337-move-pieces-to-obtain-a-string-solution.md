
+++
authors = ["grid47"]
title = "Leetcode 2337: Move Pieces to Obtain a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2337: Move Pieces to Obtain a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<int, int>> ss, ts;

        for(int i = 0; i < start.size(); i++)
        if(start[i] != '_') ss.push({start[i], i});

        for(int i = 0; i < target.size(); i++)
        if(target[i] != '_') ts.push({target[i], i});

        if(ss.size() != ts.size()) return false;

        while(!ss.empty()) {
            auto s = ss.front();
            auto t = ts.front();
            ss.pop();
            ts.pop();
            if(s.first != t.first) return false;

            if(s.first == 'L' && t.second > s.second)
            return false;
            if(t.first == 'R' && t.second < s.second)
            return false;
        }

        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2337.md" >}}
---
{{< youtube Tq2uKuSciOc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2341: Maximum Number of Pairs in Array](https://grid47.xyz/posts/leetcode-2337-move-pieces-to-obtain-a-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
