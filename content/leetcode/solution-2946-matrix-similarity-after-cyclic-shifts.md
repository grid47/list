
+++
authors = ["grid47"]
title = "Leetcode 2946: Matrix Similarity After Cyclic Shifts"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2946: Matrix Similarity After Cyclic Shifts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "7RGWUCc5IHw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for (const auto& l : mat) {
            int n = l.size();
            for (int i = 0; i < n; ++i) {
                if (l[i] != l[(i + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2946.md" >}}
---
{{< youtube 7RGWUCc5IHw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2947: Count Beautiful Substrings I](https://grid47.xyz/leetcode/solution-2947-count-beautiful-substrings-i/) |
| --- |
