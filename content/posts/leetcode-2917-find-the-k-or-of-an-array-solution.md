
+++
authors = ["grid47"]
title = "Leetcode 2917: Find the K-or of an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2917: Find the K-or of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2917.md" >}}
---
{{< youtube jNPKX6McyCg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2918: Minimum Equal Sum of Two Arrays After Replacing Zeros](https://grid47.xyz/posts/leetcode-2918-minimum-equal-sum-of-two-arrays-after-replacing-zeros-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
