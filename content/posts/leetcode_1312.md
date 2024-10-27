
+++
authors = ["Yasir"]
title = "Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome"
date = "2021-03-26"
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

**Code:**

{{< highlight html >}}
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

