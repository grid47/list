
+++
authors = ["grid47"]
title = "Leetcode 231: Power of Two"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 231: Power of Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/231.webp"
youtube = "lGxiqzurnNU"
youtube_upload_date="2020-06-08"
youtube_thumbnail="https://i.ytimg.com/vi/lGxiqzurnNU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/power-of-two/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/231.webp" 
    alt="A series of glowing numbers doubling, each number expanding into the next power of two."
    caption="Solution to LeetCode 231: Power of Two Problem"
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
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n - 1));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/231.md" >}}
---
{{< youtube lGxiqzurnNU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #232: Implement Queue using Stacks](https://grid47.xyz/leetcode/solution-232-implement-queue-using-stacks/) |
| --- |