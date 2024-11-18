
+++
authors = ["grid47"]
title = "Leetcode 2656: Maximum Sum With Exactly K Elements "
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2656: Maximum Sum With Exactly K Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "lA9B6M4E_BQ"
youtube_upload_date="2023-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lA9B6M4E_BQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        return i * k + k * (k - 1) / 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2656.md" >}}
---
{{< youtube lA9B6M4E_BQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2657: Find the Prefix Common Array of Two Arrays](https://grid47.xyz/leetcode/solution-2657-find-the-prefix-common-array-of-two-arrays/) |
| --- |
