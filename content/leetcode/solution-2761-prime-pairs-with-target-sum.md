
+++
authors = ["grid47"]
title = "Leetcode 2761: Prime Pairs With Target Sum"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2761: Prime Pairs With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rEM1dS0cKFc"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/rEM1dS0cKFc/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/prime-pairs-with-target-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    vector<vector<int>> findPrimePairs(int n) {

        vector<int> net(n + 1, true);
        net[1] = false;
        for(int i = 2; i < n / 2 + 1; i++)
        for(int j = 2; j * i < n; j++)
            net[j * i] = false;

        map<int, int> mp;
        vector<vector<int>> res;

        for(int i = 1; i < n / 2 + 1; i++)
            if(net[i] && net[n - i]) 
            res.push_back({i, n - i});

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2761.md" >}}
---
{{< youtube rEM1dS0cKFc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2762: Continuous Subarrays](https://grid47.xyz/leetcode/solution-2762-continuous-subarrays/) |
| --- |
