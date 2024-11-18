
+++
authors = ["grid47"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2024-09-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 467: Unique Substrings in Wraparound String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/467.webp" 
    alt="A glowing string where unique substrings wrap around and light up as they form distinct patterns."
    caption="Solution to LeetCode 467: Unique Substrings in Wraparound String Problem"
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
    int findSubstringInWraproundString(string p) {
        vector<int> len(26, 0);
        int cur = 1;
        len[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); i++) {
            if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
            else cur = 1;
            len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
        }
        return accumulate(len.begin(), len.end(), 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/467.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #468: Validate IP Address](https://grid47.xyz/leetcode/solution-468-validate-ip-address/) |
| --- |
