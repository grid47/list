
+++
authors = ["grid47"]
title = "Leetcode 3179: Find the N-th Value After K Seconds"
date = "2023-12-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3179: Find the N-th Value After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4sO18TX7Qzw"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4sO18TX7Qzw/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<vector<long>> mtx(k + 1, vector<long>(n, 1));
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < n; j++) {
                mtx[i][j] = (mtx[i - 1][j] + mtx[i][j - 1]) % mod;   
            }
        }
        return mtx[k][n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3179.md" >}}
---
{{< youtube 4sO18TX7Qzw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3190: Find Minimum Operations to Make All Elements Divisible by Three](https://grid47.xyz/leetcode/solution-3190-find-minimum-operations-to-make-all-elements-divisible-by-three/) |
| --- |
