
+++
authors = ["Crafted by Me"]
title = "Leetcode 2917: Find the K-or of an Array"
date = "2016-11-07"
description = "In-depth solution and explanation for Leetcode 2917: Find the K-or of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-k-or-of-an-array/description/)

---

**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0; // Initialize the answer to 0.
        
        for (int i = 0; i < 31; i++) {
            // Bit position represented by 2^i.
            int rep = (1 << i); 
            int cnt = 0; // Initialize a counter to count set bits at this position.

            // Iterate through the input vector 'nums'.
            for (auto ele : nums) {
                if (rep & ele) {
                    // If the i-th bit is set in 'ele', increment the count.
                    cnt++;
                }
            }

            // If the count of set bits at this position is greater than or equal to 'k', set the corresponding bit in the answer.
            if (cnt >= k) {
                ans = ans | rep;
            }
        }

        return ans; // Return the final answer, which is the result of the OR operation on selected bits.
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2918: Minimum Equal Sum of Two Arrays After Replacing Zeros](grid47.xyz/leetcode_2918) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

