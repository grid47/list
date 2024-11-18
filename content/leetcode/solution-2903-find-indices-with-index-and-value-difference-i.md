
+++
authors = ["grid47"]
title = "Leetcode 2903: Find Indices With Index and Value Difference I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2903: Find Indices With Index and Value Difference I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "R731s1mHVWM"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R731s1mHVWM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idif, int vdif) {

        int mn = 0, mx = 0;
        for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
            mn = nums[mn] < nums[j] ? mn : j;
            mx = nums[mx] > nums[j] ? mx : j;
            if (abs(nums[i] - nums[mn]) >= vdif)
                return {mn, i};
            if (abs(nums[i] - nums[mx]) >= vdif)
                return {mx, i};
        }
        return {-1, -1};        

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2903.md" >}}
---
{{< youtube R731s1mHVWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2904: Shortest and Lexicographically Smallest Beautiful String](https://grid47.xyz/leetcode/solution-2904-shortest-and-lexicographically-smallest-beautiful-string/) |
| --- |
