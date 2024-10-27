
+++
authors = ["Yasir"]
title = "Leetcode 1630: Arithmetic Subarrays"
date = "2020-05-12"
description = "Solution to Leetcode 1630"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/arithmetic-subarrays/description/)

---

**Code:**

{{< highlight html >}}
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

