
+++
authors = ["grid47"]
title = "Leetcode 377: Combination Sum IV"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 377: Combination Sum IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum-iv/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/377.webp" 
    alt="A glowing set of numbers forming different combinations to meet the target sum, each combination softly glowing."
    caption="Solution to LeetCode 377: Combination Sum IV Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> mem;
public:
    int combinationSum4(vector<int>& nums, int target) {
        mem.resize(target + 1, -1);
        return dp(nums, target);
    }
    
    int dp(vector<int>& nums, int left) {
        
        if(left == 0) return 1;
        if(left < 0) return 0;

        if(mem[left] != -1) return mem[left];

        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += dp(nums, left - nums[i]);

        return mem[left] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/377.md" >}}
---
{{< youtube hg_U5GVEM-k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #378: Kth Smallest Element in a Sorted Matrix](https://grid47.xyz/posts/leetcode-378-kth-smallest-element-in-a-sorted-matrix-solution/) |
| --- |
