
+++
authors = ["grid47"]
title = "Leetcode 2470: Number of Subarrays With LCM Equal to K"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2470: Number of Subarrays With LCM Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && k % nums[j] == 0; j++) {
                nums[i] = (nums[i] * nums[j] / __gcd(nums[i], nums[j]));
                cnt += nums[i] == k;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2470.md" >}}
---
{{< youtube xT-O9YJrwh4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2471: Minimum Number of Operations to Sort a Binary Tree by Level](https://grid47.xyz/posts/leetcode-2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level-solution/) |
| --- |
