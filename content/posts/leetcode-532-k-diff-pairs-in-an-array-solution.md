
+++
authors = ["grid47"]
title = "Leetcode 532: K-diff Pairs in an Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 532: K-diff Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        int res = 0;
        for(auto const &[i, j] : mp)
            if((k > 0 && mp.count(i - k)) ||
              (k == 0 && (j > 1)) )
                res++;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/532.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #535: Encode and Decode TinyURL](https://grid47.xyz/posts/leetcode-535-encode-and-decode-tinyurl-solution/) |
| --- |
