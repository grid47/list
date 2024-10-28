
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 72: Edit Distance"
date = "2024-08-18"
description = "Solution to Leetcode 72"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

