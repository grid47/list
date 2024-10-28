
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 215: Kth Largest Element in an Array"
date = "2024-03-28"
description = "Solution to Leetcode 215"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x: nums)
            pq.push(x);
        
        int x;
        while(k-->0) {
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

