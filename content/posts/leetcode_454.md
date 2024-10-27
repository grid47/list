
+++
authors = ["Yasir"]
title = "Leetcode 454: 4Sum II"
date = "2023-08-01"
description = "Solution to Leetcode 454"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/4sum-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int a : A)
        for(int b : B)
        mp[a+b]++;
        for(int c : C)
        for(int d : D)
        if(mp.count(-c-d)) res+= mp[-c-d];
        return res;
    }
};
{{< /highlight >}}

