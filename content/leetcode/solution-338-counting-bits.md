
+++
authors = ["grid47"]
title = "Leetcode 338: Counting Bits"
date = "2024-10-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 338: Counting Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/counting-bits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/338.webp" 
    alt="A glowing sequence of numbers where each bit is counted and highlighted as part of the total."
    caption="Solution to LeetCode 338: Counting Bits Problem"
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
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/338.md" >}}
---
{{< youtube RyBM56RIWrM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #341: Flatten Nested List Iterator](https://grid47.xyz/leetcode/solution-341-flatten-nested-list-iterator/) |
| --- |
