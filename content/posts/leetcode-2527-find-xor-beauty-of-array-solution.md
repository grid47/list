
+++
authors = ["grid47"]
title = "Leetcode 2527: Find Xor-Beauty of Array"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2527: Find Xor-Beauty of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-xor-beauty-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int tmp = 0;
        for(int it: nums)
            tmp ^= it;
        return tmp;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2527.md" >}}
---
{{< youtube V12dkKaSdnw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2529: Maximum Count of Positive Integer and Negative Integer](https://grid47.xyz/posts/leetcode-2529-maximum-count-of-positive-integer-and-negative-integer-solution/) |
| --- |
