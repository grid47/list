
+++
authors = ["grid47"]
title = "Leetcode 310: Minimum Height Trees"
date = "2024-10-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 310: Minimum Height Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/310.webp"
youtube = "wQGQnyv_9hI"
youtube_upload_date="2024-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/wQGQnyv_9hI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-height-trees/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/310.webp" 
    alt="A series of tree structures, with each one growing taller or shorter as the minimum height tree is highlighted."
    caption="Solution to LeetCode 310: Minimum Height Trees Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                q.push(i);
        
        vector<int> res;
        
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                res.push_back(tmp);
                for(auto nbr: adj[tmp]) {
                    degree[nbr]--;
                    if(degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/310.md" >}}
---
{{< youtube wQGQnyv_9hI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #316: Remove Duplicate Letters](https://grid47.xyz/leetcode/solution-316-remove-duplicate-letters/) |
| --- |