
+++
authors = ["grid47"]
title = "Leetcode 1376: Time Needed to Inform All Employees"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1376: Time Needed to Inform All Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d0xAcl58SXg"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/d0xAcl58SXg/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1376.md" >}}
---
{{< youtube d0xAcl58SXg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://grid47.xyz/leetcode/solution-1379-find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/) |
| --- |