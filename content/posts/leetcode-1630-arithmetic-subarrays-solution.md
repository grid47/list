
+++
authors = ["grid47"]
title = "Leetcode 1630: Arithmetic Subarrays"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1630: Arithmetic Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/arithmetic-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
            sort(begin(n), end(n));
            for (j = 2; j < n.size(); ++j)
                if (n[j] - n[j - 1] != n[1] - n[0])
                    break;
            res.push_back(j == n.size());
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1630.md" >}}
---
{{< youtube EIBRvGNsG64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1631: Path With Minimum Effort](https://grid47.xyz/posts/leetcode-1631-path-with-minimum-effort-solution/) |
| --- |
