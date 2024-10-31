
+++
authors = ["Crafted by Me"]
title = "Leetcode 1761: Minimum Degree of a Connected Trio in a Graph"
date = "2020-01-06"
description = "Solution to Leetcode 1761"
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

