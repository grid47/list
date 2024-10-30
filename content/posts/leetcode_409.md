
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 409: Longest Palindrome"
date = "2023-09-18"
description = "Solution to Leetcode 409"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindrome/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(char x: s)
            mp[x]++;
        bool odd = false;
        int res = 0;
        for(auto [key, val]: mp) {
            if(val % 2) odd = true;
            res += (val/2) * 2;
        }
        return odd? res + 1: res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/409.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

