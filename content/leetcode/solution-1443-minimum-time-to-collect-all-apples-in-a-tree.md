
+++
authors = ["grid47"]
title = "Leetcode 1443: Minimum Time to Collect All Apples in a Tree"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1443: Minimum Time to Collect All Apples in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xdt5Z583auM"
youtube_upload_date="2023-01-11"
youtube_thumbnail="https://i.ytimg.com/vi/Xdt5Z583auM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, vector<int>> gph;
    map<int, int> visited;
    vector<bool> hasApple;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->hasApple = hasApple;
        for(auto x: edges) {
            gph[x[0]].push_back(x[1]);
            gph[x[1]].push_back(x[0]);
        }
        
        return dfs(0, 0);
    }
    
    int dfs(int mycost, int node) {
        if(visited[node]) return 0;
        visited[node] = true;
        int childcost = 0;
        for(int x: gph[node]) {
            childcost += dfs(2, x);
        }
        if(childcost == 0 && hasApple[node] == false)
            return 0;
        
        return childcost + mycost;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1443.md" >}}
---
{{< youtube Xdt5Z583auM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1447: Simplified Fractions](https://grid47.xyz/leetcode/solution-1447-simplified-fractions/) |
| --- |