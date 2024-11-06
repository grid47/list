
+++
authors = ["Crafted by Me"]
title = "Leetcode 1642: Furthest Building You Can Reach"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1642: Furthest Building You Can Reach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/furthest-building-you-can-reach/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int furthestBuilding(vector<int>& h, int bri, int lad) {
        int n = h.size();
        vector<int> bc(n - 1, 0);
        
        for(int i = 0; i < n - 1; i++) {
            bc[i] = h[i + 1] - h[i] < 0 ? 0: h[i + 1] - h[i];
            // cout << bc[i] << " ";
        }
 
        // cout << "\n";
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, sum = 0;
        for(; i < n - 1; i++) {

            if(bc[i] == 0) continue;
            
            if(pq.size() < lad) {
                pq.push(bc[i]);
            } else {
                pq.push(bc[i]);
                if(sum + pq.top() <= bri)
                sum += pq.top();
                else return i;
                pq.pop();
            }
            
        }
        // cout << sum << " " << bri << " " << i;
        return n - 1;
        // Use ladders first
        // when ladders are over
        // check are them could be replaced with bricks
        // if yes, continue to assigning released ladder
        // else return where it had overflown
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1642.md" >}}
---
{{< youtube zyTeznvXCtg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1643: Kth Smallest Instructions](https://grid47.xyz/posts/leetcode_1643) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
