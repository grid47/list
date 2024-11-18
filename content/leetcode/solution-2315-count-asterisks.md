
+++
authors = ["grid47"]
title = "Leetcode 2315: Count Asterisks"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2315: Count Asterisks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "tpgDi9Saq_s"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tpgDi9Saq_s/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-asterisks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countAsterisks(string s) {
        int res = 0, sign = 1;
        for (char& c : s)
            if ((sign ^= c == '|') && c == '*')
                res++;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2315.md" >}}
---
{{< youtube tpgDi9Saq_s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2316: Count Unreachable Pairs of Nodes in an Undirected Graph](https://grid47.xyz/leetcode/solution-2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/) |
| --- |
