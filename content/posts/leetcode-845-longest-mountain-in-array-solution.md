
+++
authors = ["grid47"]
title = "Leetcode 845: Longest Mountain in Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 845: Longest Mountain in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Dynamic Programming","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-mountain-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        
        int n = arr.size();
        
        if(n < 3) return 0;

        vector<int> pre(n, 0), suf(n, 0);
        
        int cur = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1])
                cur++;
            else cur = 0;
            pre[i] = cur;
        }

        cur = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1])
                cur++;
            else cur = 0;
            suf[i] = cur;
        }
        
        for(int i = 0; i < n; i++)
            if(pre[i] > 0 && suf[i] > 0)
        res = max(pre[i] + suf[i] + 1, res);
        
        return res == 1? 0: res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/845.md" >}}
---
{{< youtube uGnRaCqWflI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #846: Hand of Straights](https://grid47.xyz/posts/leetcode-846-hand-of-straights-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}