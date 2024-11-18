
+++
authors = ["grid47"]
title = "Leetcode 392: Is Subsequence"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 392: Is Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/392.webp"
youtube = "M_OB20n4hfo"
youtube_upload_date="2024-06-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/M_OB20n4hfo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/is-subsequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/392.webp" 
    alt="A sequence of characters gently forming into a subsequence, glowing as each match is found."
    caption="Solution to LeetCode 392: Is Subsequence Problem"
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
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        int sdx = 0, tdx = 0;
        // sdx is sub seq of tdx

        for(; tdx < t.size(); tdx++) {
            if(t[tdx] == s[sdx]) sdx++;
            if(sdx == s.size()) return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/392.md" >}}
---
{{< youtube M_OB20n4hfo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #393: UTF-8 Validation](https://grid47.xyz/leetcode/solution-393-utf-8-validation/) |
| --- |
