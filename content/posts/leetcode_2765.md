
+++
authors = ["Crafted by Me"]
title = "Leetcode 2765: Longest Alternating Subarray"
date = "2017-04-08"
description = "In-depth solution and explanation for Leetcode 2765: Longest Alternating Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-alternating-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int n = A.size(), res = 0, j = 0;
        for (int i = 0; i < n; ++i)
            for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
                res = max(res, j - i + 1);
        return res > 1 ? res : -1;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2766: Relocate Marbles](https://grid47.xyz/posts/leetcode_2766) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

