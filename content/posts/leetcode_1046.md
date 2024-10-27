
+++
authors = ["Yasir"]
title = "Leetcode 1046: Last Stone Weight"
date = "2021-12-17"
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

**Code:**

{{< highlight html >}}
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

