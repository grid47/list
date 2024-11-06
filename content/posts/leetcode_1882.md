
+++
authors = ["Crafted by Me"]
title = "Leetcode 1882: Process Tasks Using Servers"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1883: Minimum Skips to Arrive at Meeting On Time](https://grid47.xyz/posts/leetcode_1883) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
