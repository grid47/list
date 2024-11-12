
+++
authors = ["grid47"]
title = "Leetcode 2365: Task Scheduler II"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2365: Task Scheduler II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/task-scheduler-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        map<int, long long> mp;
        
        long long n= tasks.size(), days = 0;
        
        int i = 0;
        while(i < n) {
            if(mp.count(tasks[i])) {
                if(days - mp[tasks[i]] > space) {
                    mp[tasks[i]] = days;
                    days++;
                    i++;
                } else {
                    days = mp[tasks[i]] + space + 1;
                }
            } else {
                mp[tasks[i]] = days;                
                days++;
                i++;
            }
        }
        
        
        return days;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2365.md" >}}
---
{{< youtube iuiNCc0HkX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2367: Number of Arithmetic Triplets](https://grid47.xyz/posts/leetcode-2367-number-of-arithmetic-triplets-solution/) |
| --- |
