
+++
authors = ["grid47"]
title = "Leetcode 1144: Decrease Elements To Make Array Zigzag"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1144: Decrease Elements To Make Array Zigzag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), left, right;
        vector<int> res(2, 0);
        for(int i = 0; i < n; i++) {

            left  = ( i     > 0 ) ? nums[i - 1] : 1001;
            right = ( i + 1 < n ) ? nums[i + 1] : 1001;

            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
        }

        return min(res[0], res[1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1144.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1145: Binary Tree Coloring Game](https://grid47.xyz/leetcode/solution-1145-binary-tree-coloring-game/) |
| --- |
