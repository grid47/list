
+++
authors = ["grid47"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1685: Sum of Absolute Differences in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "WYe644djV30"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
        vector<int> ans(n, 0);
        ans[0] = z;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1685.md" >}}
---
{{< youtube WYe644djV30 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1686: Stone Game VI](https://grid47.xyz/leetcode/solution-1686-stone-game-vi/) |
| --- |
