
+++
authors = ["Crafted by Me"]
title = "Leetcode 2673: Make Costs of Paths Equal in a Binary Tree"
date = "2016-07-08"
description = "Solution to Leetcode 2673"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            res += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

