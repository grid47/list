
+++
authors = ["grid47"]
title = "Leetcode 775: Global and Local Inversions"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 775: Global and Local Inversions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/global-and-local-inversions/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/775.webp" 
    alt="A sequence where global and local inversions are counted, each inversion glowing softly as it's identified."
    caption="Solution to LeetCode 775: Global and Local Inversions Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int cmax = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if(cmax > nums[i + 2]) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/775.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #777: Swap Adjacent in LR String](https://grid47.xyz/leetcode/solution-777-swap-adjacent-in-lr-string/) |
| --- |
