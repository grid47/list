
+++
authors = ["Crafted by Me"]
title = "Leetcode 207: Course Schedule"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 207: Course Schedule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> cnt(n, 0);

        // Created graph and dependecy counter
        for(int i = 0; i < pre.size(); i++) {
            graph[pre[i][1]].push_back(pre[i][0]);
            cnt[pre[i][0]]++;
        }

         queue<int> q;

        // Triaged course which does not have any dependency.
        for(int i = 0; i < n; i++)
            if(cnt[i] == 0)
                q.push(i);
       

        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                int course = q.front();
                q.pop();
                for(int dep: graph[course]) {

                    cnt[dep]--;

                    if(cnt[dep] == 0) {
                        q.push(dep);
                    }
                }                
            }
        }

        for(int i = 0; i < n; i++)
            if(cnt[i] != 0)
                return false;   

        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/207.md" >}}
---
{{< youtube IWLpZbu1wco >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #208: Implement Trie (Prefix Tree)](https://grid47.xyz/posts/leetcode_208) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
