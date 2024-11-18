
+++
authors = ["grid47"]
title = "Leetcode 191: Number of 1 Bits"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 191: Number of 1 Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/191.webp"
youtube = "1JfdvPk-iHg"
youtube_upload_date="2024-08-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1JfdvPk-iHg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-1-bits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/191.webp" 
    alt="A glowing sequence of bits, with 1's gently illuminating and highlighting their presence."
    caption="Solution to LeetCode 191: Number of 1 Bits Problem"
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
    int hammingWeight(uint32_t n) {
        int key = 0;
        while(n) {
            n = n & (n - 1);
            key++;
        }
        return key;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/191.md" >}}
---
{{< youtube 1JfdvPk-iHg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #198: House Robber](https://grid47.xyz/leetcode/solution-198-house-robber/) |
| --- |
