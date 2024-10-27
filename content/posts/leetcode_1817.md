
+++
authors = ["Yasir"]
title = "Leetcode 1817: Finding the Users Active Minutes"
date = "2019-11-07"
description = "Solution to Leetcode 1817"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/finding-the-users-active-minutes/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> res(k);
        for(auto &l : logs) 
        m[l[0]].insert(l[1]);
        for(auto &p: m)
        ++res[p.second.size() - 1];
        return res;
    }
};
{{< /highlight >}}

