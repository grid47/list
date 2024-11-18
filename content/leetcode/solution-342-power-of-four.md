
+++
authors = ["grid47"]
title = "Leetcode 342: Power of Four"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 342: Power of Four in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "qEYZPwnlM0U"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/342.webp"
+++



[`Problem Link`](https://leetcode.com/problems/power-of-four/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/342.webp" 
    alt="A glowing series of numbers where each number doubles and highlights the powers of four along the way."
    caption="Solution to LeetCode 342: Power of Four Problem"
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
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/342.md" >}}
---
{{< youtube qEYZPwnlM0U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #343: Integer Break](https://grid47.xyz/leetcode/solution-343-integer-break/) |
| --- |
