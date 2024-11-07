
+++
authors = ["Crafted by Me"]
title = "Leetcode 1466: Reorder Routes to Make All Paths Lead to the City Zero"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1466: Reorder Routes to Make All Paths Lead to the City Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<int>> grid(n);
        
        map<int, map<int, bool>> mp;
        
        for(auto it: conn) {
            grid[it[0]].push_back(it[1]);
            grid[it[1]].push_back(it[0]);
            mp[it[0]][it[1]] = true;
        }
        int cnt = 0;
        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        vis[0] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                for(int it: grid[tmp]) {
                    if(vis[it]) continue;
                    vis[it] = true;
                    if(mp.count(tmp) && mp[tmp].count(it)) cnt++;
                    q.push(it);
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1466.md" >}}
---
{{< youtube qL4UaMAdPts >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1471: The k Strongest Values in an Array](https://grid47.xyz/posts/leetcode_1471) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
