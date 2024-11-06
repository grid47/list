
+++
authors = ["Crafted by Me"]
title = "Leetcode 1122: Relative Sort Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1122: Relative Sort Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/relative-sort-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size();
        int a2i[1001];

        fill(a2i, end(a2i), n2);
        for(int i=0; i<n2; i++)
            a2i[arr2[i]]=i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if (a2i[x]==a2i[y]) return x<y;
            return a2i[x]<a2i[y];
        });
        return arr1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1122.md" >}}
---
{{< youtube OPvcR1e4lfg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1123: Lowest Common Ancestor of Deepest Leaves](https://grid47.xyz/posts/leetcode_1123) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
