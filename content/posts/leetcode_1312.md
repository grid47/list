
+++
authors = ["Crafted by Me"]
title = "Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome"
date = "2021-03-31"
description = "In-depth solution and explanation for Leetcode 1312: Minimum Insertion Steps to Make a String Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1312.md" >}}
---
{{< youtube ggQlIW5keAA >}}
| Next : [LeetCode #1313: Decompress Run-Length Encoded List](https://grid47.xyz/posts/leetcode_1313) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

