
+++
authors = ["grid47"]
title = "Leetcode 89: Gray Code"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 89: Gray Code in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/gray-code/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/89.webp" 
    alt="A peaceful, spiraling Gray code sequence glowing softly as it shifts from one value to the next."
    caption="Solution to LeetCode 89: Gray Code Problem"
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
    vector<int> grayCode(int n) {
        vector<int> res = {0};

        for (int idx = 0; idx < n; idx++) {
            int sz = res.size();
            for (int jdx = sz - 1; jdx >= 0; jdx--)
                res.push_back(res[jdx] | (1 << idx));
        }

        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/89.md" >}}
---
{{< youtube k5UYQtKXJGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #90: Subsets II](https://grid47.xyz/leetcode/solution-90-subsets-ii/) |
| --- |
