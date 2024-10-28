
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 841: Keys and Rooms"
date = "2022-07-11"
description = "Solution to Leetcode 841"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

