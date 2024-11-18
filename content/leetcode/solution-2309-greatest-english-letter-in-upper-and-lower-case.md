
+++
authors = ["grid47"]
title = "Leetcode 2309: Greatest English Letter in Upper and Lower Case"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2309: Greatest English Letter in Upper and Lower Case in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "C37FoUne7gc"
youtube_upload_date="2022-06-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/C37FoUne7gc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string greatestLetter(string s) {
        int cnt[128] = {};
        for (auto ch : s)
            ++cnt[ch];
        for (auto ch = 'Z'; ch >= 'A'; --ch)
            if (cnt[ch] && cnt[ch + 'a' - 'A'])
                return string(1, ch);
        return "";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2309.md" >}}
---
{{< youtube C37FoUne7gc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2311: Longest Binary Subsequence Less Than or Equal to K](https://grid47.xyz/leetcode/solution-2311-longest-binary-subsequence-less-than-or-equal-to-k/) |
| --- |
