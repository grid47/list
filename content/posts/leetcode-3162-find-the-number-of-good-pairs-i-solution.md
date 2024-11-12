
+++
authors = ["grid47"]
title = "Leetcode 3162: Find the Number of Good Pairs I"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3162: Find the Number of Good Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int res = 0, m = nums1.size(), n = nums2.size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(nums1[i] % (nums2[j] * k) == 0) res++;
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3162.md" >}}
---
{{< youtube S-Q4eFfzGNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #3163: String Compression III](https://grid47.xyz/posts/leetcode-3163-string-compression-iii-solution/) |
| --- |
