
+++
authors = ["grid47"]
title = "Leetcode 207: Course Schedule"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 207: Course Schedule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/207.webp" 
    alt="A calming flowchart with courses linking together, showing dependencies in a gentle, glowing path."
    caption="Solution to LeetCode 207: Course Schedule Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #208: Implement Trie (Prefix Tree)](https://grid47.xyz/posts/leetcode-208-implement-trie-prefix-tree-solution/) |
| --- |
