
+++
authors = ["Crafted by Me"]
title = "Leetcode 910: Smallest Range II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 910: Smallest Range II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-range-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {

public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
        
        int res = nums[n - 1] - nums[0];
        for(int i = 0; i < n - 1; i++) {
            int maxi = max(nums[i] + k, right);
            int mini = min(nums[i + 1] - k, left);
            res = min(res, maxi - mini);
        }
        
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/910.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #911: Online Election](https://grid47.xyz/posts/leetcode_911) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

