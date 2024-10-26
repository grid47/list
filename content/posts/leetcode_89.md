
+++
authors = ["Yasir"]
title = "Leetcode 89: Gray Code"
date = "2024-07-30"
description = "Solution to Leetcode 89"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/gray-code/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};

        for (int idx = 0; idx < n; idx++) {
            int sz = res.size();
            for (int jdx = sz - 1; jdx >= 0; jdx--)
                res.push_back(res[jdx] | (1 << idx));
        }

        return res;        
    }
};
{{< /highlight >}}

