
+++
authors = ["grid47"]
title = "Leetcode 1827: Minimum Operations to Make the Array Increasing"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1827: Minimum Operations to Make the Array Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "U217V1lFwlk"
youtube_upload_date="2021-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/U217V1lFwlk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, need = nums[0] + 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            res += max(0, need - nums[i]);
            need = max(nums[i], need) + 1;
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1827.md" >}}
---
{{< youtube U217V1lFwlk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1828: Queries on Number of Points Inside a Circle](https://grid47.xyz/leetcode/solution-1828-queries-on-number-of-points-inside-a-circle/) |
| --- |