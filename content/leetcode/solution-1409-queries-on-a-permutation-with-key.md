
+++
authors = ["grid47"]
title = "Leetcode 1409: Queries on a Permutation With Key"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1409: Queries on a Permutation With Key in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1410: HTML Entity Parser](https://grid47.xyz/leetcode/solution-1410-html-entity-parser/) |
| --- |
