
+++
authors = ["Crafted by Me"]
title = "Leetcode 2946: Matrix Similarity After Cyclic Shifts"
date = "2016-10-09"
description = "In-depth solution and explanation for Leetcode 2946: Matrix Similarity After Cyclic Shifts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


| Next : [LeetCode #2947: Count Beautiful Substrings I](grid47.xyz/leetcode_2947) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

