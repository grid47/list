
+++
authors = ["Crafted by Me"]
title = "Leetcode 1705: Maximum Number of Eaten Apples"
date = "2020-03-03"
description = "In-depth solution and explanation for Leetcode 1705: Maximum Number of Eaten Apples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-eaten-apples/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int n = days.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int res = 0, i = 0;
        
        while(i < n || !pq.empty()) {

            if(i < n && apples[i] > 0) pq.push({i + days[i] - 1, apples[i]});
            
            while(!pq.empty() && pq.top()[0] < i)
                pq.pop();
            
            if(!pq.empty()) {
                res++;
                auto it = pq.top();
                pq.pop();
                if(it[1] > 1) pq.push({it[0], it[1] - 1});
            }
            i++;
        }
            
        return res;
    }
};
{{< /highlight >}}


---


"| 1706: Where Will the Ball Fall |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

