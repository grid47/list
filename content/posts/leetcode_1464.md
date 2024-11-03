
+++
authors = ["Crafted by Me"]
title = "Leetcode 1464: Maximum Product of Two Elements in an Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1464: Maximum Product of Two Elements in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (int num : nums) {
            if (num >= max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1464.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://grid47.xyz/posts/leetcode_1465) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

