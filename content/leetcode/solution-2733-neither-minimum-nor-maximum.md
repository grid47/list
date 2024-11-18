
+++
authors = ["grid47"]
title = "Leetcode 2733: Neither Minimum nor Maximum"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2733: Neither Minimum nor Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6Wg_vntUAA"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/n6Wg_vntUAA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/neither-minimum-nor-maximum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNonMinOrMax(vector<int>& A) {
        if (A.size() < 3)
            return -1;
        int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
        for (int i = 0; i < 3; ++i)
            if (mn < A[i] && A[i] < mx)
                return A[i];
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2733.md" >}}
---
{{< youtube n6Wg_vntUAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2734: Lexicographically Smallest String After Substring Operation](https://grid47.xyz/leetcode/solution-2734-lexicographically-smallest-string-after-substring-operation/) |
| --- |
