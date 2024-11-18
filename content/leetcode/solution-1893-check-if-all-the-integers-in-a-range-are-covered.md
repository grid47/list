
+++
authors = ["grid47"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1893: Check if All the Integers in a Range Are Covered in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {};
        for (auto &r : ranges) {
            line[r[0]] += 1;
            line[r[1] + 1] -= 1;
        }
        for (int i = 1, overlaps = 0; i <= right; ++i) {
            overlaps += line[i];
            if (i >= left && overlaps == 0)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1893.md" >}}
---
{{< youtube hZ7QlMbyaKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1898: Maximum Number of Removable Characters](https://grid47.xyz/leetcode/solution-1898-maximum-number-of-removable-characters/) |
| --- |
