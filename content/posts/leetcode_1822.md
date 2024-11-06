
+++
authors = ["Crafted by Me"]
title = "Leetcode 1822: Sign of the Product of an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1822: Sign of the Product of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sign-of-the-product-of-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sgn = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                sgn = 0;
                break;
            } else if(nums[i] > 0) {
                
            } else if(nums[i] < 0) {
                sgn *= -1;
            }
        }
        return sgn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1822.md" >}}
---
{{< youtube 5qwGgOEHL3U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1823: Find the Winner of the Circular Game](https://grid47.xyz/posts/leetcode_1823) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

