
+++
authors = ["grid47"]
title = "Leetcode 1462: Course Schedule IV"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1462: Course Schedule IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1464: Maximum Product of Two Elements in an Array](https://grid47.xyz/leetcode/solution-1464-maximum-product-of-two-elements-in-an-array/) |
| --- |
