
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1882: Process Tasks Using Servers"
date = "2019-09-05"
description = "Solution to Leetcode 1882"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

