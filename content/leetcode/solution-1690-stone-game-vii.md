
+++
authors = ["grid47"]
title = "Leetcode 1690: Stone Game VII"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1690: Stone Game VII in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "cOGliK5brbQ"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-vii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001] = {};
    int dp(vector<int>& s, int i, int j, int sum) {
        
        if(i == j) {
            return 0;
        }
        
        
        return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
                                            sum - s[j] - dp(s, i, j - 1, sum - s[j]));
    }
    
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        return dp(s, 0,n-1, accumulate(begin(s), end(s), 0));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1690.md" >}}
---
{{< youtube cOGliK5brbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1694: Reformat Phone Number](https://grid47.xyz/leetcode/solution-1694-reformat-phone-number/) |
| --- |
