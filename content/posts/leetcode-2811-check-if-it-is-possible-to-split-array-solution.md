
+++
authors = ["grid47"]
title = "Leetcode 2811: Check if it is Possible to Split Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2811: Check if it is Possible to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] + nums[i + 1] >= m)
                return true;
        return nums.size() < 3;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2811.md" >}}
---
{{< youtube BVkYLy-gzcg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2812: Find the Safest Path in a Grid](https://grid47.xyz/posts/leetcode-2812-find-the-safest-path-in-a-grid-solution/) |
| --- |
