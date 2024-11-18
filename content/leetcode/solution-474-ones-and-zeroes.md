
+++
authors = ["grid47"]
title = "Leetcode 474: Ones and Zeroes"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 474: Ones and Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/474.webp"
youtube = "miZ3qV04b1g"
youtube_upload_date="2023-03-02"
youtube_thumbnail="https://i.ytimg.com/vi/miZ3qV04b1g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/ones-and-zeroes/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/474.webp" 
    alt="A sequence of ones and zeroes gently forming various combinations, with each valid combination glowing softly."
    caption="Solution to LeetCode 474: Ones and Zeroes Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        int i, j, p = strs.size();
        vector<vector<int>> dp(zeros + 1, vector<int>(ones+1));

        for(auto &s : strs) {
            int currOne = count(s.begin(), s.end(), '1');
            int currZero = s.size() - currOne;
            for(int j = ones ; j >= currOne; j--) 
            for(int i = zeros; i >= currZero; i--) {
               dp[i][j] = max(dp[i][j], 1 + dp[i- currZero ][j-currOne]);
            }
        }

        return dp[zeros][ones];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/474.md" >}}
---
{{< youtube miZ3qV04b1g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #475: Heaters](https://grid47.xyz/leetcode/solution-475-heaters/) |
| --- |
