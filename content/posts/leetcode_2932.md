
+++
authors = ["Crafted by Me"]
title = "Leetcode 2932: Maximum Strong Pair XOR I"
date = "2016-10-23"
description = "In-depth solution and explanation for Leetcode 2932: Maximum Strong Pair XOR I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strong-pair-xor-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))){
                // cout << nums[i] << " " << nums[j] << "\n";
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}


---


"| 2933: High-Access Employees |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

