
+++
authors = ["Crafted by Me"]
title = "Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements "
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, l = -1, r = -1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
              l = i;
              break;
            }
        }
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
              r = i;
              break;
            }
        }
        if(l < r) return r - l;
        return 0;
    }
};
{{< /highlight >}}


---
{{< youtube V3SamYLfPtg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2149: Rearrange Array Elements by Sign](https://grid47.xyz/posts/leetcode_2149) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

