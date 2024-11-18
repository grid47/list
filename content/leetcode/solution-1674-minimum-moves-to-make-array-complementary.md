
+++
authors = ["grid47"]
title = "Leetcode 1674: Minimum Moves to Make Array Complementary"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1674: Minimum Moves to Make Array Complementary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "uyV0p6zy9DU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMoves(vector<int>& num, int lmt) {
        int n = num.size();
        vector<int> dp(2*lmt +2,0);
        for(int i = 0; i < n/2; i++) {
            int a = num[i];
            int b = num[n-1-i];
            dp[2] += 2;
            dp[min(a,b)+1] -= 1;
            dp[a+b] -= 1;
            dp[a+b+1] += 1;
            dp[max(a,b) + lmt +1] += 1;
            
            }
        //for(int i = 1; i < n; i++)
           // dp[i] += dp[i - 1];
        
        int cur = 0, res = 2* n;
        for(int i = 2; i < 2 * lmt + 1; i++) {
            cur += dp[i];
            res = min(res, cur);
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1674.md" >}}
---
{{< youtube uyV0p6zy9DU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1678: Goal Parser Interpretation](https://grid47.xyz/leetcode/solution-1678-goal-parser-interpretation/) |
| --- |
