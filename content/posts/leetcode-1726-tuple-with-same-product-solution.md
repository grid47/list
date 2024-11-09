
+++
authors = ["grid47"]
title = "Leetcode 1726: Tuple with Same Product"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1726: Tuple with Same Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tuple-with-same-product/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int x = nums[i] * nums[j];
            if(mp.count(x)) res+=mp[x];
            mp[x]++;
        }
        return res * 8;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1726.md" >}}
---
{{< youtube asI_UBkXI0M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1727: Largest Submatrix With Rearrangements](https://grid47.xyz/posts/leetcode-1727-largest-submatrix-with-rearrangements-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
