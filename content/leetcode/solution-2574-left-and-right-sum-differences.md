
+++
authors = ["grid47"]
title = "Leetcode 2574: Left and Right Sum Differences"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2574: Left and Right Sum Differences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "O3pCkMbVsFQ"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/O3pCkMbVsFQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/left-and-right-sum-differences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0), ans(n, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        for(int i = 0; i < n; i++) {
            ans[i] = abs(net - sum[i + 1] - sum[i]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2574.md" >}}
---
{{< youtube O3pCkMbVsFQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2575: Find the Divisibility Array of a String](https://grid47.xyz/leetcode/solution-2575-find-the-divisibility-array-of-a-string/) |
| --- |