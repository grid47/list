
+++
authors = ["Crafted by Me"]
title = "Leetcode 1462: Course Schedule IV"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1462: Course Schedule IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule-iv/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& q) {
        
        vector<vector<bool>> reach(num, vector<bool>(num, false));
        
        vector<vector<int>> grid(num);
        for(auto it: pre) {
            grid[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < num; i++) {
            queue<int> q;
            q.push(i);
            vector<int> vis(num, 0);            
            vis[i] = true;
            while(!q.empty()) {
                int sz = q.size();
                while(sz--) {
                    int tmp = q.front();

                    q.pop();
                    for(int it: grid[tmp]) {
                        reach[i][it] = true;
                        if(vis[it]) continue;
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            
        }
        
        vector<bool> ans(q.size());
        for(int i = 0; i < q.size(); i++) {
            // is q[0] a pre of q[1];
            ans[i] = reach[q[i][0]][q[i][1]];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1462.md" >}}
---
{{< youtube cEW05ofxhn0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1463: Cherry Pickup II](https://grid47.xyz/posts/leetcode_1463) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

