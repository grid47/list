
+++
authors = ["grid47"]
title = "Leetcode 1941: Check if All Characters Have Equal Number of Occurrences"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1941: Check if All Characters Have Equal Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "PG9qfNf5vLw"
youtube_upload_date="2021-07-24"
youtube_thumbnail="https://i.ytimg.com/vi/PG9qfNf5vLw/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {}, m_cnt = 0;
        for (auto ch : s)
            m_cnt = max(m_cnt, ++cnt[ch - 'a']);
        return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1941.md" >}}
---
{{< youtube PG9qfNf5vLw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1942: The Number of the Smallest Unoccupied Chair](https://grid47.xyz/leetcode/solution-1942-the-number-of-the-smallest-unoccupied-chair/) |
| --- |