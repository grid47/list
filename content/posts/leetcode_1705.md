
+++
authors = ["Crafted by Me"]
title = "Leetcode 1705: Maximum Number of Eaten Apples"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1705: Maximum Number of Eaten Apples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1705.md" >}}
---
{{< youtube 1vRYTJqaZ8s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1706: Where Will the Ball Fall](https://grid47.xyz/posts/leetcode_1706) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
