
+++
authors = ["grid47"]
title = "Leetcode 1029: Two City Scheduling"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1029: Two City Scheduling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d-B_gk_gJtQ"
youtube_upload_date="2022-03-25"
youtube_thumbnail="https://i.ytimg.com/vi/d-B_gk_gJtQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/two-city-scheduling/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
        
        2n people - interview
        
        
        */
        int mc = 0;
        vector<int> refund;
        
        for(auto c : costs) {
            mc += c[0];
            refund.push_back(c[1] - c[0]);
        }
        sort(refund.begin(), refund.end());
        int n = costs.size()/ 2;
        
        for(int i = 0; i < n; i++) {
            mc += refund[i];
        }
        
        return mc;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1029.md" >}}
---
{{< youtube d-B_gk_gJtQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1031: Maximum Sum of Two Non-Overlapping Subarrays](https://grid47.xyz/leetcode/solution-1031-maximum-sum-of-two-non-overlapping-subarrays/) |
| --- |