
+++
authors = ["grid47"]
title = "Leetcode 2765: Longest Alternating Subarray"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2765: Longest Alternating Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Yg_VhAOIIuk"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/Yg_VhAOIIuk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-alternating-subarray/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int n = A.size(), res = 0, j = 0;
        for (int i = 0; i < n; ++i)
            for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
                res = max(res, j - i + 1);
        return res > 1 ? res : -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2765.md" >}}
---
{{< youtube Yg_VhAOIIuk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2766: Relocate Marbles](https://grid47.xyz/leetcode/solution-2766-relocate-marbles/) |
| --- |