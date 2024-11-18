
+++
authors = ["grid47"]
title = "Leetcode 2006: Count Number of Pairs With Absolute Difference K"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2006: Count Number of Pairs With Absolute Difference K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "noP_AsQlgQc"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/noP_AsQlgQc/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {}, res = 0;
        for (auto n : nums)
            ++cnt[n];
        for (int i = k + 1; i < 101; ++i)
            res += cnt[i] * cnt[i - k];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2006.md" >}}
---
{{< youtube noP_AsQlgQc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2007: Find Original Array From Doubled Array](https://grid47.xyz/leetcode/solution-2007-find-original-array-from-doubled-array/) |
| --- |
