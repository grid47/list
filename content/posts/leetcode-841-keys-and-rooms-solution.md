
+++
authors = ["grid47"]
title = "Leetcode 841: Keys and Rooms"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 841: Keys and Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/keys-and-rooms/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        vis[0] = true;
        dfs(rooms, vis, 0);
        
        for(auto x: vis)
            if(!x) return x;
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool> &vis, int cur) {
        vis[cur] = true;
        for(auto x: rooms[cur]) {
            if(!vis[x])
                dfs(rooms, vis, x);
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/841.md" >}}
---
{{< youtube i89fYz8JX7U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #842: Split Array into Fibonacci Sequence](https://grid47.xyz/posts/leetcode-842-split-array-into-fibonacci-sequence-solution/) |
| --- |
