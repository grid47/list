
+++
authors = ["grid47"]
title = "Leetcode 763: Partition Labels"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 763: Partition Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-labels/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> res;
        int prv = -1, mx = mp[s[0]];
        for(int i = 0; i < s.size(); i++) {
            mx = max(mx, mp[s[i]]);
            if(i == mx || i == s.size() - 1) {
                res.push_back(i - prv);
                prv = mx;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/763.md" >}}
---
{{< youtube B7m8UmZE-vw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #764: Largest Plus Sign](https://grid47.xyz/posts/leetcode-764-largest-plus-sign-solution/) |
| --- |
