
+++
authors = ["Yasir"]
title = "Leetcode 409: Longest Palindrome"
date = "2023-09-14"
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

{{< highlight html >}}
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

