
+++
authors = ["grid47"]
title = "Leetcode 779: K-th Symbol in Grammar"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 779: K-th Symbol in Grammar in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/779.webp"
youtube = "pmD2HCKaqRQ"
youtube_upload_date="2023-10-25"
youtube_thumbnail="https://i.ytimg.com/vi/pmD2HCKaqRQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/k-th-symbol-in-grammar/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/779.webp" 
    alt="A sequence where the kth symbol is found, glowing softly as it is located."
    caption="Solution to LeetCode 779: K-th Symbol in Grammar Problem"
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
    int kthGrammar(int n, int k) {
        if (n == 1)   return 0;
        if (k%2 == 0) return kthGrammar(n - 1,       k / 2) == 0? 1 : 0;
        else          return kthGrammar(n - 1, (k + 1) / 2) == 0? 0 : 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/779.md" >}}
---
{{< youtube pmD2HCKaqRQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #781: Rabbits in Forest](https://grid47.xyz/leetcode/solution-781-rabbits-in-forest/) |
| --- |
