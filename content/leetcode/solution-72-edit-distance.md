
+++
authors = ["grid47"]
title = "Leetcode 72: Edit Distance"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 72: Edit Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "XYi2-LPrwm4"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/72.webp"
+++



[`Problem Link`](https://leetcode.com/problems/edit-distance/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/72.webp" 
    alt="Two strings gently transforming into one another, symbolizing subtle edits."
    caption="Solution to LeetCode 72: Edit Distance Problem"
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
    string a, b;
    vector<vector<int>> memo;
    
    int dp(int i, int j) {
        if(i == a.size() && j == b.size()) return 0;
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(a[i] != b[j]) {
            ans = min({dp(i+1,j), dp(i,j+1), dp(i+1,j+1)}) + 1;
        } else {
            ans = dp(i + 1, j+ 1);
        }
        return memo[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        this->a = word1;
        this->b = word2;
        memo.resize(a.size(), vector<int>(b.size(), -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/72.md" >}}
---
{{< youtube XYi2-LPrwm4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #73: Set Matrix Zeroes](https://grid47.xyz/leetcode/solution-73-set-matrix-zeroes/) |
| --- |
