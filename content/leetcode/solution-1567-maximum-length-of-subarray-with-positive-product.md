
+++
authors = ["grid47"]
title = "Leetcode 1567: Maximum Length of Subarray With Positive Product"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1567: Maximum Length of Subarray With Positive Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bFer5PdsgpY"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/bFer5PdsgpY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, positive = 0, negative = 0;
        for(int x : nums) {
            if (x == 0) {
                positive = 0;
                negative = 0;
            }
            else if (x > 0) {
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            }
            else {
                int tmp  = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = tmp + 1;
            }
            ans = max(ans, positive);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1567.md" >}}
---
{{< youtube bFer5PdsgpY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1572: Matrix Diagonal Sum](https://grid47.xyz/leetcode/solution-1572-matrix-diagonal-sum/) |
| --- |
