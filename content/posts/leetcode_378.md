
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 378: Kth Smallest Element in a Sorted Matrix"
date = "2023-10-17"
description = "Solution to Leetcode 378"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mtx, int k) {
        int m = mtx.size(), n = mtx[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for(int r = 0; r < min(m, k); r++)
            pq.push({mtx[r][0], r, 0});
        
        vector<int> cur;
        while(k-- > 1 && !pq.empty()) {
            
            cur = pq.top();
            pq.pop();
            
            if(cur[2] + 1 < n)
            pq.push({ mtx[cur[1]][cur[2] + 1], cur[1], cur[2] + 1 });
            
        }
        
        cur = pq.top();
        
        return cur[0];
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

