
+++
authors = ["grid47"]
title = "Leetcode 1282: Group the People Given the Group Size They Belong To"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1282: Group the People Given the Group Size They Belong To in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gz) {
        vector<vector<int>> res, gzs(gz.size() + 1);
        for(auto i = 0; i < gz.size(); i++) {
            gzs[gz[i]].push_back(i);
            if(gzs[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), gzs[gz[i]]);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1282.md" >}}
---
{{< youtube RrnhHjJmzj8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1283: Find the Smallest Divisor Given a Threshold](https://grid47.xyz/posts/leetcode-1283-find-the-smallest-divisor-given-a-threshold-solution/) |
| --- |
