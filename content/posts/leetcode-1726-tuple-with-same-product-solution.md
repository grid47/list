
+++
authors = ["grid47"]
title = "Leetcode 1726: Tuple with Same Product"
date = "2024-05-18"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1727: Largest Submatrix With Rearrangements](https://grid47.xyz/posts/leetcode-1727-largest-submatrix-with-rearrangements-solution/) |
| --- |
