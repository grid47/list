
+++
authors = ["grid47"]
title = "Leetcode 1877: Minimize Maximum Pair Sum in Array"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1877: Minimize Maximum Pair Sum in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gAzUiJ1ylQc"
youtube_upload_date="2021-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gAzUiJ1ylQc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPairSum(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < n / 2; ++i)
            res = max(res, A[i] + A[n - i - 1]);
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1877.md" >}}
---
{{< youtube gAzUiJ1ylQc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1878: Get Biggest Three Rhombus Sums in a Grid](https://grid47.xyz/leetcode/solution-1878-get-biggest-three-rhombus-sums-in-a-grid/) |
| --- |
