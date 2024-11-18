
+++
authors = ["grid47"]
title = "Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        int dp[1 << 17] = {1};
        dp[0] = 1;
        for(int a : nums) {
            for(int i = mx; i >= 0; i--) {
                dp[i | a] += dp[i];
            }
            mx |= a;
        }
        return dp[mx];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2044.md" >}}
---
{{< youtube _wBj3IMV7tY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2047: Number of Valid Words in a Sentence](https://grid47.xyz/leetcode/solution-2047-number-of-valid-words-in-a-sentence/) |
| --- |
