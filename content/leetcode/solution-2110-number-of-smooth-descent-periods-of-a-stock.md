
+++
authors = ["grid47"]
title = "Leetcode 2110: Number of Smooth Descent Periods of a Stock"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2110: Number of Smooth Descent Periods of a Stock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "p_hKOwJ7azU"
youtube_upload_date="2021-12-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/p_hKOwJ7azU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        dp[0] = 1;
        long long ans = 1;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] == prices[i - 1] - 1)
            dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;
            ans += dp[i];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2110.md" >}}
---
{{< youtube p_hKOwJ7azU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2116: Check if a Parentheses String Can Be Valid](https://grid47.xyz/leetcode/solution-2116-check-if-a-parentheses-string-can-be-valid/) |
| --- |
