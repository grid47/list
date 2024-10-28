
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2279: Maximum Bags With Full Capacity of Rocks"
date = "2018-08-03"
description = "Solution to Leetcode 2279"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rock, int cnt) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = rock.size();
        
        for(int i = 0; i < n; i++)
            pq.push(cap[i] - rock[i]);
        
        int res = 0;
        
        while(!pq.empty() && cnt >= pq.top()) {
            res++;
            cnt -= pq.top();
            pq.pop();
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

