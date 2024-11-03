
+++
authors = ["Crafted by Me"]
title = "Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkArray(vector<int>& A, int k) {
        int cur = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (cur > A[i])
                return false;
            A[i] -= cur;
            cur += A[i];
            if (i >= k - 1)
                cur -= A[i - k + 1];
        }
        return cur == 0;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2773: Height of Special Binary Tree](https://grid47.xyz/posts/leetcode_2773) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

