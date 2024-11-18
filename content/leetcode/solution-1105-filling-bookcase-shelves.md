
+++
authors = ["grid47"]
title = "Leetcode 1105: Filling Bookcase Shelves"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1105: Filling Bookcase Shelves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lFYPPPTp8qE"
youtube_upload_date="2024-07-31"
youtube_thumbnail="https://i.ytimg.com/vi/lFYPPPTp8qE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/filling-bookcase-shelves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + books[i][1];
            int sum = 0, height = 0;
            for(int j = i; j >= 0; j--) {
                sum += books[j][0];
                if(sum > shelfWidth) break;
                else {
                    height = max(height, books[j][1]);
                    dp[i + 1] = min(dp[j] + height, dp[i+1]);
                }
            }
        }
        return dp[n];        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1105.md" >}}
---
{{< youtube lFYPPPTp8qE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1109: Corporate Flight Bookings](https://grid47.xyz/leetcode/solution-1109-corporate-flight-bookings/) |
| --- |
