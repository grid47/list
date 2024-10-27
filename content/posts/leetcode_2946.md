
+++
authors = ["Yasir"]
title = "Leetcode 2946: Matrix Similarity After Cyclic Shifts"
date = "2016-10-04"
description = "Solution to Leetcode 2946"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for (const auto& l : mat) {
            int n = l.size();
            for (int i = 0; i < n; ++i) {
                if (l[i] != l[(i + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
{{< /highlight >}}

