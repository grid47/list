
+++
authors = ["Yasir"]
title = "Leetcode 2924: Find Champion II"
date = "2016-10-27"
description = "Solution to Leetcode 2924"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-champion-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1, count = 0;
        vector<int> indegree(n, 0);
        for(auto e: edges) indegree[e[1]]++;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {count++; ans = i; }
        }
        return count > 1?-1:ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

