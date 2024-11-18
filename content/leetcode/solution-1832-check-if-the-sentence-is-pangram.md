
+++
authors = ["grid47"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1832: Check if the Sentence Is Pangram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rk82ArzlPHM"
youtube_upload_date="2021-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rk82ArzlPHM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkIfPangram(string set) {
        bitset<26> bit;
        for(char x: set) bit.set(x - 'a');
        return bit.count() == 26;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1832.md" >}}
---
{{< youtube rk82ArzlPHM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1833: Maximum Ice Cream Bars](https://grid47.xyz/leetcode/solution-1833-maximum-ice-cream-bars/) |
| --- |
