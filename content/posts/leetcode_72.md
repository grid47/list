
+++
authors = ["Crafted by Me"]
title = "Leetcode 72: Edit Distance"
date = "2024-08-22"
description = "In-depth solution and explanation for Leetcode 72: Edit Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/edit-distance/description/)

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
| Next : [LeetCode #73: Set Matrix Zeroes](https://grid47.xyz/posts/leetcode_73) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

