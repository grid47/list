
+++
authors = ["Crafted by Me"]
title = "Leetcode 1877: Minimize Maximum Pair Sum in Array"
date = "2018-09-12"
description = "Solution to Leetcode 1877"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

