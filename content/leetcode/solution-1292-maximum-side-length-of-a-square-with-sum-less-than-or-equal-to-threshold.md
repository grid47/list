
+++
authors = ["grid47"]
title = "Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "2Y2a9VbqiC4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int hit) {
        int m = mat.size(), n = mat[0].size();
        int res = 0, len = 1;
        vector<vector<int>> sum(m + 1, vector<int> (n + 1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
                if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                    res = len++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1292.md" >}}
---
{{< youtube 2Y2a9VbqiC4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1296: Divide Array in Sets of K Consecutive Numbers](https://grid47.xyz/leetcode/solution-1296-divide-array-in-sets-of-k-consecutive-numbers/) |
| --- |
