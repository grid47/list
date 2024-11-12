
+++
authors = ["grid47"]
title = "Leetcode 1464: Maximum Product of Two Elements in an Array"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1464: Maximum Product of Two Elements in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
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
{{< youtube XJ1pYgzimYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://grid47.xyz/posts/leetcode-1465-maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts-solution/) |
| --- |
