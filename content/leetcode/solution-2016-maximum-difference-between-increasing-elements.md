
+++
authors = ["grid47"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2016: Maximum Difference Between Increasing Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OmNZRgKr7GQ"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/OmNZRgKr7GQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2016.md" >}}
---
{{< youtube OmNZRgKr7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2017: Grid Game](https://grid47.xyz/leetcode/solution-2017-grid-game/) |
| --- |
