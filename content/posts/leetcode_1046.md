
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1046: Last Stone Weight"
date = "2021-12-20"
description = "Solution to Leetcode 1046"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-stone-weight/description/)

---
{{< youtube bmcFr1AdiJg >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int x: stones) {
            pq.push(x);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            
            int y = pq.top();
             pq.pop();
             if(y == x) {}
             else {
                    pq.push(abs(y-x));
             }            
        }
        return 0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

