
+++
authors = ["Crafted by Me"]
title = "Leetcode 2447: Number of Subarrays With GCD Equal to K"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2447: Number of Subarrays With GCD Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int subarrayGCD(vector<int>& nums, int k) {        
        int cnt = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && nums[j] % k == 0; j++) {
                nums[i] = __gcd(nums[i], nums[j]);
                cnt += (nums[i] == k);
            }
        }
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube QEvLvINq730 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2448: Minimum Cost to Make Array Equal](https://grid47.xyz/posts/leetcode_2448) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

