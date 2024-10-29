
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2365: Task Scheduler II"
date = "2018-05-10"
description = "Solution to Leetcode 2365"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

