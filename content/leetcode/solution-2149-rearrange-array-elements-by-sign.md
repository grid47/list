
+++
authors = ["grid47"]
title = "Leetcode 2149: Rearrange Array Elements by Sign"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2149: Rearrange Array Elements by Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int idxpos = 0, idxneg = 1;
        for(int num: nums) {
            if(num > 0) {
                ans[idxpos] = num;
                idxpos += 2;
            }
            if(num < 0) {
                ans[idxneg] = num;
                idxneg += 2;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2149.md" >}}
---
{{< youtube SoPmcGzz9-E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2150: Find All Lonely Numbers in the Array](https://grid47.xyz/leetcode/solution-2150-find-all-lonely-numbers-in-the-array/) |
| --- |
