
+++
authors = ["Crafted by Me"]
title = "Leetcode 1330: Reverse Subarray To Maximize Array Value"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1330: Reverse Subarray To Maximize Array Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int net = 0;
        for(int i =1; i < n; i++)
            net += abs(nums[i] - nums[i - 1]);
        
        int res = INT_MIN, mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            res = max(res, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            res = max(res, abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
            mn = min(max(nums[i], nums[i + 1]), mn);
            mx = max(min(nums[i], nums[i + 1]), mx);
        }
        
        return net + max(res, (mx - mn) * 2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1330.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1331: Rank Transform of an Array](https://grid47.xyz/posts/leetcode_1331) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

