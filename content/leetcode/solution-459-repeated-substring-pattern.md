
+++
authors = ["grid47"]
title = "Leetcode 459: Repeated Substring Pattern"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 459: Repeated Substring Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/459.webp"
youtube = "p92_kEjyJAo"
youtube_upload_date="2020-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/p92_kEjyJAo/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGUgYShMMA8=&rs=AOn4CLCIMqAUIe8EdHdk18s3dwcMWJj5hw"
+++



[`Problem Link`](https://leetcode.com/problems/repeated-substring-pattern/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/459.webp" 
    alt="A string where repeated substrings softly glow, showing the patterns and repetitions clearly."
    caption="Solution to LeetCode 459: Repeated Substring Pattern Problem"
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
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/459.md" >}}
---
{{< youtube p92_kEjyJAo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #467: Unique Substrings in Wraparound String](https://grid47.xyz/leetcode/solution-467-unique-substrings-in-wraparound-string/) |
| --- |