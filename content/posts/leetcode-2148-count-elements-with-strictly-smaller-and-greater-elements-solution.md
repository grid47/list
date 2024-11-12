
+++
authors = ["grid47"]
title = "Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements "
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Counting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2148.md" >}}
---
{{< youtube V3SamYLfPtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2149: Rearrange Array Elements by Sign](https://grid47.xyz/posts/leetcode-2149-rearrange-array-elements-by-sign-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
