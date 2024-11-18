
+++
authors = ["grid47"]
title = "Leetcode 2956: Find Common Elements Between Two Arrays"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2956: Find Common Elements Between Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "jb1IbKe3bPE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-common-elements-between-two-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1, n2;
        for(int x: nums1) n1.insert(x);
        for(int x: nums2) n2.insert(x);
        int cnt1 = 0;
        for(int x: nums1) if(n2.count(x)) cnt1++;
        int cnt2 = 0;
        for(int x: nums2) if(n1.count(x)) cnt2++;        
        return vector<int>{cnt1, cnt2};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2956.md" >}}
---
{{< youtube jb1IbKe3bPE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2957: Remove Adjacent Almost-Equal Characters](https://grid47.xyz/leetcode/solution-2957-remove-adjacent-almost-equal-characters/) |
| --- |
