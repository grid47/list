
+++
authors = ["Crafted by Me"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 769: Max Chunks To Make Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-chunks-to-make-sorted/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();

        int res = 0, mx = arr[0];

        for(int i = 0; i < n; i++) {
            
            mx = max(mx, arr[i]);
            res += (mx == i);
            
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/769.md" >}}
---
{{< youtube b3Mf8c7hKjk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #775: Global and Local Inversions](https://grid47.xyz/posts/leetcode_775) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
