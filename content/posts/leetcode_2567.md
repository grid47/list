
+++
authors = ["Crafted by Me"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2567: Minimum Score by Changing Two Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 3] - nums[0];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 2] - nums[1];
        return min({a, b, c});
        
    }
};
{{< /highlight >}}


---
{{< youtube MPtncVNtKW0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2568: Minimum Impossible OR](https://grid47.xyz/posts/leetcode_2568) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

