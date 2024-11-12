
+++
authors = ["grid47"]
title = "Leetcode 565: Array Nesting"
date = "2024-09-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 565: Array Nesting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-nesting/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mxsize = 0;
        for(int i = 0; i < nums.size(); i++) {
            int size = 0;
            for(int k = i; nums[k] >= 0; size++) {
                int ak = nums[k];
                nums[k] = -1;
                k = ak;
            }
            mxsize = max(size, mxsize);
        }
        return mxsize;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/565.md" >}}
---
{{< youtube rl_hXXzvTiM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #567: Permutation in String](https://grid47.xyz/posts/leetcode-567-permutation-in-string-solution/) |
| --- |
