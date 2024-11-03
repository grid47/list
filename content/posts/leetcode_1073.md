
+++
authors = ["Crafted by Me"]
title = "Leetcode 1073: Adding Two Negabinary Numbers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1073: Adding Two Negabinary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/adding-two-negabinary-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int carry = 0, i = arr1.size() -1, j = arr2.size() -1;
        vector<int> res;
        while(carry || i >= 0 || j >= 0) {
            if(i >= 0) carry += arr1[i--];
            if(j >= 0) carry += arr2[j--];
            res.push_back(carry&1);
            carry = -(carry>>1);
        }
        while(res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1073.md" >}}
---
{{< youtube mrK37adgvjo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1074: Number of Submatrices That Sum to Target](https://grid47.xyz/posts/leetcode_1074) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

