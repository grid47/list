
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1376: Time Needed to Inform All Employees"
date = "2021-01-22"
description = "Solution to Leetcode 1376"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> gph;
        for(int i = 0; i < manager.size(); i++)
        gph[manager[i]].push_back(i);
        
        return dfs(headID, gph, informTime);
    }
    
    int dfs(int cur, map<int, vector<int>> &gph, vector<int> &it) {
        if(!gph.count(cur)) return 0;
        
        int mx = 0;
        for(auto x: gph[cur])
            mx = max(mx, dfs(x, gph, it));
        
        return mx + it[cur];
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

