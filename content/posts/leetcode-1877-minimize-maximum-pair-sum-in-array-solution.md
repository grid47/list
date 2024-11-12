
+++
authors = ["grid47"]
title = "Leetcode 1877: Minimize Maximum Pair Sum in Array"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1877: Minimize Maximum Pair Sum in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPairSum(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < n / 2; ++i)
            res = max(res, A[i] + A[n - i - 1]);
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1877.md" >}}
---
{{< youtube gAzUiJ1ylQc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1878: Get Biggest Three Rhombus Sums in a Grid](https://grid47.xyz/posts/leetcode-1878-get-biggest-three-rhombus-sums-in-a-grid-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
