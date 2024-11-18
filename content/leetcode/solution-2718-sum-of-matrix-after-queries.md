
+++
authors = ["grid47"]
title = "Leetcode 2718: Sum of Matrix After Queries"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2718: Sum of Matrix After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GgRr0TbbsO0"
youtube_upload_date="2023-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/GgRr0TbbsO0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-matrix-after-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long res = 0;

        int seen[2][10001] = {};
        int cnt[2] = {n, n};

        for(int i = q.size() - 1; i >= 0; i--) {
            
            int type = q[i][0], id = q[i][1], val = q[i][2];
            
            if(!seen[type][id]) {
                seen[type][id] = 1;
                res += val * cnt[!type];
                --cnt[type];
            }
            
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2718.md" >}}
---
{{< youtube GgRr0TbbsO0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2729: Check if The Number is Fascinating](https://grid47.xyz/leetcode/solution-2729-check-if-the-number-is-fascinating/) |
| --- |
