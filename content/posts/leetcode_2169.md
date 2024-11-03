
+++
authors = ["Crafted by Me"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2169: Count Operations to Obtain Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube yPqe3KshvVo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2170: Minimum Operations to Make the Array Alternating](https://grid47.xyz/posts/leetcode_2170) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

