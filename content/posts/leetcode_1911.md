
+++
authors = ["Crafted by Me"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2019-08-10"
description = "In-depth solution and explanation for Leetcode 1911: Maximum Alternating Subsequence Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long odd = 0, even = 0;

        for(int num : nums) {
            even = max(even, odd + num);
            odd = even - num;
        }

        return even;
    }
};
{{< /highlight >}}


---
{{< youtube 4v42XOuU1XA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1912: Design Movie Rental System](https://grid47.xyz/posts/leetcode_1912) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

