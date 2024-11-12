
+++
authors = ["grid47"]
title = "Leetcode 621: Task Scheduler"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 621: Task Scheduler in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/task-scheduler/description/)

---
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
---
{{< youtube s8p8ukTyA2I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #622: Design Circular Queue](https://grid47.xyz/posts/leetcode-622-design-circular-queue-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
