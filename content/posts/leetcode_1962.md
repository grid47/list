
+++
authors = ["Crafted by Me"]
title = "Leetcode 1962: Remove Stones to Minimize the Total"
date = "2019-06-19"
description = "Solution to Leetcode 1962"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < piles.size(); i++)
            pq.push(piles[i]);
        
        while(k--) {
            int top = pq.top();
            top = top - floor(top/2);
            pq.pop();
            if(top > 0)
            pq.push(top);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

