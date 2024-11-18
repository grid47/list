
+++
authors = ["grid47"]
title = "Leetcode 1653: Minimum Deletions to Make String Balanced"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1653: Minimum Deletions to Make String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WDStNufBUQ8"
youtube_upload_date="2024-07-30"
youtube_thumbnail="https://i.ytimg.com/vi/WDStNufBUQ8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            char a = s[i];
            if(a == 'a') {                
                dp[i + 1] = min(dp[i] + 1, bcnt);
            } else {
                bcnt++;
                dp[i + 1] = dp[i];
            }
        }
        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1653.md" >}}
---
{{< youtube WDStNufBUQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1656: Design an Ordered Stream](https://grid47.xyz/leetcode/solution-1656-design-an-ordered-stream/) |
| --- |
