
+++
authors = ["Crafted by Me"]
title = "Leetcode 1962: Remove Stones to Minimize the Total"
date = "2019-06-20"
description = "In-depth solution and explanation for Leetcode 1962: Remove Stones to Minimize the Total in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


| Next : [LeetCode #1963: Minimum Number of Swaps to Make the String Balanced](grid47.xyz/leetcode_1963) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

