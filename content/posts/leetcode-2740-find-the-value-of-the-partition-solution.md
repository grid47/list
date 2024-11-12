
+++
authors = ["grid47"]
title = "Leetcode 2740: Find the Value of the Partition"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2740: Find the Value of the Partition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-value-of-the-partition/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res = min(nums[i] - nums[i - 1], res);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2740.md" >}}
---
{{< youtube WeaM8AiavbY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2741: Special Permutations](https://grid47.xyz/posts/leetcode-2741-special-permutations-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
