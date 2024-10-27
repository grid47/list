
+++
authors = ["Yasir"]
title = "Leetcode 997: Find the Town Judge"
date = "2022-02-04"
description = "Solution to Leetcode 997"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-town-judge/description/)

---

**Code:**

{{< highlight html >}}

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n + 1, 0);
        for(auto x: trust) {
            deg[x[1]]++;
            deg[x[0]]--;
        }
        for(int i = 1; i <= n; i++)
            if(deg[i] == n - 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}

