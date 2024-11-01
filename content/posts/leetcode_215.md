
+++
authors = ["Crafted by Me"]
title = "Leetcode 215: Kth Largest Element in an Array"
date = "2024-04-01"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/215.md" >}}
- by gpt
        
---
{{< youtube ZmGk7h8KZLs >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

