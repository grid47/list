
+++
authors = ["grid47"]
title = "Leetcode 1046: Last Stone Weight"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1046: Last Stone Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-stone-weight/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1046.md" >}}
---
{{< youtube bmcFr1AdiJg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1048: Longest String Chain](https://grid47.xyz/posts/leetcode-1048-longest-string-chain-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}