
+++
authors = ["grid47"]
title = "Leetcode 190: Reverse Bits"
date = "2024-10-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 190: Reverse Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp"
youtube = "epFf0wlbng0"
youtube_upload_date="2020-07-13"
youtube_thumbnail="https://i.ytimg.com/vi/epFf0wlbng0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/reverse-bits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp" 
    alt="A series of bits glowing as they reverse, shifting smoothly from 1 to 0 and back."
    caption="Solution to LeetCode 190: Reverse Bits Problem"
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
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
        n = (n & 0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8;
        n = (n & 0x0f0f0f0f) << 4  | (n & 0xf0f0f0f0) >> 4;
        n = (n & 0x33333333) << 2  | (n & 0xcccccccc) >> 2;
        n = (n & 0x55555555) << 1  | (n & 0xaaaaaaaa) >> 1;        
        return n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/190.md" >}}
---
{{< youtube epFf0wlbng0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #191: Number of 1 Bits](https://grid47.xyz/leetcode/solution-191-number-of-1-bits/) |
| --- |