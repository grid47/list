
+++
authors = ["grid47"]
title = "Leetcode 1854: Maximum Population Year"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1854: Maximum Population Year in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Counting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2W2yijatcTY"
youtube_upload_date="2021-05-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2W2yijatcTY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-population-year/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;
            sum[v[0] - 1950]++;
        }
        
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {
                yr = i + 1950;
                mx = sum[i];
            }
        }
        return yr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1854.md" >}}
---
{{< youtube 2W2yijatcTY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1855: Maximum Distance Between a Pair of Values](https://grid47.xyz/leetcode/solution-1855-maximum-distance-between-a-pair-of-values/) |
| --- |
