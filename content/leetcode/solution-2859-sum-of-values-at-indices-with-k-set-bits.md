
+++
authors = ["grid47"]
title = "Leetcode 2859: Sum of Values at Indices With K Set Bits"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2859: Sum of Values at Indices With K Set Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ditzt6BYVEs"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ditzt6BYVEs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
      int res = 0;

      for(int i = 0; i < nums.size(); i++) {
        int c = 0;
        int copy = i;
        while(copy) {
            c += copy & 1;
            copy >>= 1;
        }
        if(c == k) {
            res += nums[i];
        }
      }

      return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2859.md" >}}
---
{{< youtube Ditzt6BYVEs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2860: Happy Students](https://grid47.xyz/leetcode/solution-2860-happy-students/) |
| --- |
