
+++
authors = ["Crafted by Me"]
title = "Leetcode 2134: Minimum Swaps to Group All 1's Together II"
date = "2018-12-30"
description = "In-depth solution and explanation for Leetcode 2134: Minimum Swaps to Group All 1's Together II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
        ones = count(nums.begin(), nums.end(), 1);
        vector<int> nums2(2 *n);
        for(int i = 0; i < 2 * n; i++)
        nums2[i] = nums[i%n];
        for(int i = 0; i < 2 *n ; i++) {
            if(i >= ones && nums2[i - ones] == 1) x--;
            if(nums2[i] == 1) x++;
            onesInWindows = max(x, onesInWindows);
        }
        return ones - onesInWindows;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2135: Count Words Obtained After Adding a Letter](grid47.xyz/leetcode_2135) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

