
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome"
date = "2021-03-29"
description = "Solution to Leetcode 1312"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

---
{{< youtube ggQlIW5keAA >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    vector<vector<int>> memo;
    int dp(int i, int j) {
        if(i == j) return 0;
        if(i == j - 1) return s[i] == s[j]? 0: 1;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        if(s[i] == s[j]) {
            return memo[i][j]= dp(i + 1, j - 1);
        }
        return memo[i][j] = 1 + min(dp(i + 1, j), dp(i, j - 1)); 
    }
    
    int minInsertions(string str) {
        s = str;
        memo.resize(s.size(), vector<int>(s.size(), -1));
        return dp(0, s.size() - 1);
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

