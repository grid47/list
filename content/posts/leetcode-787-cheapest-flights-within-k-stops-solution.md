
+++
authors = ["grid47"]
title = "Leetcode 787: Cheapest Flights Within K Stops"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 787: Cheapest Flights Within K Stops in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Depth-First Search","Breadth-First Search","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/787.webp" 
    alt="A map where the cheapest flight path is calculated, glowing softly as the optimal path is found."
    caption="Solution to LeetCode 787: Cheapest Flights Within K Stops Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/787.md" >}}
---
{{< youtube WDxnQSAvNbI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #788: Rotated Digits](https://grid47.xyz/posts/leetcode-788-rotated-digits-solution/) |
| --- |
