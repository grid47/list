
+++
authors = ["grid47"]
title = "Leetcode 2133: Check if Every Row and Column Contains All Numbers"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2133: Check if Every Row and Column Contains All Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6l0_5Weq-3k"
youtube_upload_date="2022-01-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6l0_5Weq-3k/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkValid(vector<vector<int>>& mtx) {
        int n = mtx.size();
        for(int i = 0; i < n; i++) {
          bitset<101> row, col;
          for(int j = 0; j < n; j++)
            row[mtx[i][j]] = col[mtx[j][i]] = true;
          if (min(row.count(), col.count()) < n)
            return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2133.md" >}}
---
{{< youtube 6l0_5Weq-3k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2134: Minimum Swaps to Group All 1's Together II](https://grid47.xyz/leetcode/solution-2134-minimum-swaps-to-group-all-1s-together-ii/) |
| --- |
