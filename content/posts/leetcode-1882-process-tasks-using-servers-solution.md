
+++
authors = ["grid47"]
title = "Leetcode 1882: Process Tasks Using Servers"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1882: Process Tasks Using Servers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/process-tasks-using-servers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
        
        int n = servers.size();
        for(int i = 0; i < n; i++)
            avail.push({0, servers[i], i});
        
        int m = tasks.size();
        
        vector<int> ans;        
        
        for(int t = 0; t < m; t++) {
            
            while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
                auto [time, w, idx] = busy.top();
                busy.pop();
                avail.push({time <= t? 0: time, w, idx});
            }

            auto [time, w, idx] = avail.top();
            avail.pop();
            busy.push({ max(time, (long)t) + tasks[t], w, idx});
            ans.push_back(idx);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1882.md" >}}
---
{{< youtube XKA22PecuMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1886: Determine Whether Matrix Can Be Obtained By Rotation](https://grid47.xyz/posts/leetcode-1886-determine-whether-matrix-can-be-obtained-by-rotation-solution/) |
| --- |
