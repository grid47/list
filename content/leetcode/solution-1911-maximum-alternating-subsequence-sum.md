
+++
authors = ["grid47"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1911: Maximum Alternating Subsequence Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4v42XOuU1XA"
youtube_upload_date="2021-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/4v42XOuU1XA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long odd = 0, even = 0;

        for(int num : nums) {
            even = max(even, odd + num);
            odd = even - num;
        }

        return even;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1911.md" >}}
---
{{< youtube 4v42XOuU1XA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1913: Maximum Product Difference Between Two Pairs](https://grid47.xyz/leetcode/solution-1913-maximum-product-difference-between-two-pairs/) |
| --- |