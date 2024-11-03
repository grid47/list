
+++
authors = ["Crafted by Me"]
title = "Leetcode 210: Course Schedule II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 210: Course Schedule II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Graph","Topological Sort","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> gph(n);
        vector<int> incnt(n, 0);
        for(int i = 0; i < pre.size(); i++) {
            gph[pre[i][1]].push_back(pre[i][0]);
            incnt[pre[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(incnt[i] == 0)
                q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int y = q.front();
            ans.push_back(y);
            q.pop();
            for(auto x: gph[y]) {
                incnt[x]--;
                if(incnt[x] == 0)
                    q.push(x);
            }
        }
        return ans.size() == n? ans: vector<int>();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/210.md" >}}
---
{{< youtube 2cpihwDznaw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #211: Design Add and Search Words Data Structure](https://grid47.xyz/posts/leetcode_211) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

