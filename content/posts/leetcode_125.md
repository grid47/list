
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-06-28"
description = "Solution to Leetcode 125"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-palindrome/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(!isalnum(s[i])) {
                i++; continue;
            }
            if(!isalnum(s[j])) {
                j--; continue;
            }
            if(tolower(s[i]) == tolower(s[j])) {
                i++, j--;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/125.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

