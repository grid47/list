
+++
authors = ["grid47"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2413: Smallest Even Multiple in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MTdr8qNSWf8"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MTdr8qNSWf8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/smallest-even-multiple/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2413.md" >}}
---
{{< youtube MTdr8qNSWf8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2414: Length of the Longest Alphabetical Continuous Substring](https://grid47.xyz/leetcode/solution-2414-length-of-the-longest-alphabetical-continuous-substring/) |
| --- |
