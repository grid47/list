
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2410: Maximum Matching of Players With Trainers"
date = "2018-03-25"
description = "Solution to Leetcode 2410"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& man, vector<int>& master) {
        
        priority_queue<int, vector<int>, greater<int>> pq, qq;
        
        int m = man.size(), n = master.size();
        
        for(int i = 0; i < m; i++) {
            pq.push(man[i]);
        }
        for(int i = 0; i < n; i++) {
            qq.push(master[i]);
        }
        int cnt = 0;
        while(!pq.empty() && !qq.empty()) {
            while(!qq.empty() && pq.top() > qq.top())
                qq.pop();
            if(!qq.empty()) {
                cnt++;
                qq.pop();
                pq.pop();
            }
        }
        
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

