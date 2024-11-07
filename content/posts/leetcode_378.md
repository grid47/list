
+++
authors = ["Crafted by Me"]
title = "Leetcode 378: Kth Smallest Element in a Sorted Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 378: Kth Smallest Element in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Heap (Priority Queue)","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/378.md" >}}
---
{{< youtube PKj4LyF5iCk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #380: Insert Delete GetRandom O(1)](https://grid47.xyz/posts/leetcode_380) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
