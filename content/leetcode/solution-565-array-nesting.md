
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
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/565.webp" 
    alt="An array where elements are nested, each valid nesting glowing softly as it is processed."
    caption="Solution to LeetCode 565: Array Nesting Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #567: Permutation in String](https://grid47.xyz/leetcode/solution-567-permutation-in-string/) |
| --- |
