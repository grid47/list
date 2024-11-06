
+++
authors = ["Crafted by Me"]
title = "Leetcode 1535: Find the Winner of an Array Game"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1535: Find the Winner of an Array Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-winner-of-an-array-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;
        int j = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[j]) {
                cnt++;
            } else {
                cnt = 1;
                j = i;
            }
            if(cnt == k) return arr[j];            
        }
        return arr[j];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1535.md" >}}
---
{{< youtube v6On1TQfMTU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1536: Minimum Swaps to Arrange a Binary Grid](https://grid47.xyz/posts/leetcode_1536) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
