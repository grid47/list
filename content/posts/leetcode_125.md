
+++
authors = ["Yasir"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-06-24"
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

{{< highlight html >}}
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

