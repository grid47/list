
+++
authors = ["Crafted by Me"]
title = "Leetcode 2365: Task Scheduler II"
date = "2024-11-01"
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


---
{{< youtube iuiNCc0HkX8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2366: Minimum Replacements to Sort the Array](https://grid47.xyz/posts/leetcode_2366) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
