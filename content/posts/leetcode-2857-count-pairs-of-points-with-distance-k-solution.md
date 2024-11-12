
+++
authors = ["grid47"]
title = "Leetcode 2857: Count Pairs of Points With Distance k"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2857: Count Pairs of Points With Distance k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> count;
        int res = 0;
        for (auto& c : coordinates) {
            for (int x = 0; x <= k; x++)
                if (count[c[0] ^ x].count(c[1] ^ (k - x)))
                    res += count[c[0] ^ x][c[1] ^ (k - x)];
            count[c[0]][c[1]]++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2857.md" >}}
---
{{< youtube Z7hDq-nGzUI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2859: Sum of Values at Indices With K Set Bits](https://grid47.xyz/posts/leetcode-2859-sum-of-values-at-indices-with-k-set-bits-solution/) |
| --- |
