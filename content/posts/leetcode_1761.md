
+++
authors = ["Crafted by Me"]
title = "Leetcode 1761: Minimum Degree of a Connected Trio in a Graph"
date = "2020-01-07"
description = "In-depth solution and explanation for Leetcode 1761: Minimum Degree of a Connected Trio in a Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> al(n + 1);
    vector<int> cnt(n + 1);
    int res = INT_MAX;
    for (auto &e: edges) {
        al[min(e[0], e[1])].insert(max(e[0], e[1]));
        ++cnt[e[0]];
        ++cnt[e[1]];
    }
    for (auto t1 = 1; t1 <= n; ++t1)
        for (auto it2 = begin(al[t1]); it2 != end(al[t1]); ++it2)
            for (auto it3 = next(it2); it3 != end(al[t1]); ++it3)
                if (al[*it2].count(*it3))
                    res = min(res, cnt[t1] + cnt[*it2] + cnt[*it3] - 6);
    return res == INT_MAX ? -1 : res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1761.md" >}}
---
{{< youtube F_rmpodwBBQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1762: Buildings With an Ocean View](https://grid47.xyz/posts/leetcode_1762) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

