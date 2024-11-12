
+++
authors = ["grid47"]
title = "Leetcode 553: Optimal Division"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 553: Optimal Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/optimal-division/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s = "";
        if(nums.size() == 1) return to_string(nums[0]);
        if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

        for(int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + "/";
            if(i == 0)
                s += "(";
        }
        s[s.size() -1] = ')';
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/553.md" >}}
---
{{< youtube SFNvfrvWxVQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #554: Brick Wall](https://grid47.xyz/posts/leetcode-554-brick-wall-solution/) |
| --- |
