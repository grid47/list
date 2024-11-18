
+++
authors = ["grid47"]
title = "Leetcode 2466: Count Ways To Build Good Strings"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2466: Count Ways To Build Good Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "t0QkjXhE02g"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/t0QkjXhE02g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans = (ans + score(i, dp, zero, one)) % mod;
        }
        return ans;
    }

    int score(int target, vector<int> &dp, int zero, int one) {
        if(target == 0)      return 1;
        if(target < 1 )      return 0;
        if(dp[target] != -1) return dp[target];

        long long sum = score(target - zero, dp, zero, one) + score(target - one, dp, zero, one);

        return dp[target] = sum % mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2466.md" >}}
---
{{< youtube t0QkjXhE02g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2467: Most Profitable Path in a Tree](https://grid47.xyz/leetcode/solution-2467-most-profitable-path-in-a-tree/) |
| --- |
