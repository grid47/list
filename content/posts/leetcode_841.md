
+++
authors = ["Crafted by Me"]
title = "Leetcode 841: Keys and Rooms"
date = "2022-07-15"
description = "In-depth solution and explanation for Leetcode 841: Keys and Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| Next : [LeetCode #842: Split Array into Fibonacci Sequence](https://grid47.xyz/posts/leetcode_842) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

