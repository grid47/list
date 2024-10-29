
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 5: Longest Palindromic Substring"
date = "2024-10-25"
description = "Solution to Leetcode 5"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindromic-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lo, len;
    string longestPalindrome(string s) {
        len = 0;
        
        for(int i = 0; i < s.size(); i++) {
            pal(s, i, i);
            pal(s, i, i + 1);
        }
        return s.substr(lo, len);
    }
    
    void pal(string &s, int i, int j) {
        while(i >= 0 && j <= s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if(len < j - i - 1) {
            lo = i + 1;
            len = j - i - 1;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/5.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

