
+++
authors = ["grid47"]
title = "Leetcode 1247: Minimum Swaps to Make Strings Equal"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1247: Minimum Swaps to Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i++) {
                 if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        if(xy % 2 != yx % 2) return -1;
        return xy/2 + yx/2 + (xy%2) * 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1247.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1248: Count Number of Nice Subarrays](https://grid47.xyz/leetcode/solution-1248-count-number-of-nice-subarrays/) |
| --- |