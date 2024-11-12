
+++
authors = ["grid47"]
title = "Leetcode 2598: Smallest Missing Non-negative Integer After Operations"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2598: Smallest Missing Non-negative Integer After Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[(nums[i] < 0? (nums[i] % value + value)%value: nums[i]%value)]++;
        }
        int idx = 0, mn = INT_MAX;
        for(int i = 0; i < value; i++) {
            if(mp[i] < mn) {
                idx = i;
                mn = mp[i];
            }
        }
        return mn * value + idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2598.md" >}}
---
{{< youtube NztQwlNn1XA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2600: K Items With the Maximum Sum](https://grid47.xyz/posts/leetcode-2600-k-items-with-the-maximum-sum-solution/) |
| --- |
