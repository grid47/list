
+++
authors = ["grid47"]
title = "Leetcode 870: Advantage Shuffle"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 870: Advantage Shuffle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/advantage-shuffle/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(begin(nums1), end(nums1));
        for ( auto i = 0; i < nums2.size(); i++) {
            auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
            nums1[i] = *p;
            s.erase(p);
        }
        return nums1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/870.md" >}}
---
{{< youtube fY310tCXS_E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #872: Leaf-Similar Trees](https://grid47.xyz/leetcode/solution-872-leaf-similar-trees/) |
| --- |
