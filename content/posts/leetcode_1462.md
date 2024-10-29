
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1462: Course Schedule IV"
date = "2020-10-29"
description = "Solution to Leetcode 1462"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

