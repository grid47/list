
+++
authors = ["Crafted by Me"]
title = "Leetcode 621: Task Scheduler"
date = "2023-02-19"
description = "Solution to Leetcode 621"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/task-scheduler/description/)

---

{{< youtube s8p8ukTyA2I >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // if(n == 0) return tasks.size();
        map<char, int> mp;
        for(char x: tasks)
            mp[x]++;
        priority_queue<pair<int, char>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        int time = 0, net = 0;
        while(!pq.empty()) {
            vector<pair<int, char>> tmp;
            time = 0;
            for(int i = 0; i < n + 1; i++) {
                if(!pq.empty()) {
                    // cout<<pq.top().first << " ";
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(auto it: tmp) {
                it.first--;
                if(it.first)
                    pq.push(it);
            }
            net += !pq.empty()? n + 1: time;
        }
        return net;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/621.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

