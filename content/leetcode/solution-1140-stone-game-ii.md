
+++
authors = ["grid47"]
title = "Leetcode 1140: Stone Game II"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1140: Stone Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Prefix Sum","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I-z-u0zfQtg"
youtube_upload_date="2023-05-26"
youtube_thumbnail="https://i.ytimg.com/vi/I-z-u0zfQtg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    /*
    
    Taking postfix sum to count pile is new concept - residual count
    
    Thinking like, I had taken this much and pick what you
    require out of remaining, from how much ever you picked
    the rest is mine
    
    each call is others turn
    
    */
    vector<int> piles;
    vector<vector<int>> memo;
    int n;
    int dp(int idx, int m) {
        if(idx + 2* m >= piles.size()) return piles[idx];
        if(memo[idx][m] != -1) return memo[idx][m];
        int ans = 0;
        int tmp = 0;
        for(int x = 1; x <= 2 * m; x++) {
            int tmp = piles[idx] - piles[idx + x];
            ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
        }
        return memo[idx][m] = ans;
    }
    int stoneGameII(vector<int>& p) {
        n = p.size();
        piles = p;
        memo.resize(n, vector<int>(n, -1));
        for(int i = p.size() - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
        return dp(0, 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1140.md" >}}
---
{{< youtube I-z-u0zfQtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1143: Longest Common Subsequence](https://grid47.xyz/leetcode/solution-1143-longest-common-subsequence/) |
| --- |