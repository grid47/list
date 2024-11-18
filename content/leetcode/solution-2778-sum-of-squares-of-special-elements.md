
+++
authors = ["grid47"]
title = "Leetcode 2778: Sum of Squares of Special Elements "
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2778: Sum of Squares of Special Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-squares-of-special-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(n % (i + 1) == 0) ans += nums[i] * nums[i];
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2778.md" >}}
---
{{< youtube 7eI3tsBVCi4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2780: Minimum Index of a Valid Split](https://grid47.xyz/leetcode/solution-2780-minimum-index-of-a-valid-split/) |
| --- |
