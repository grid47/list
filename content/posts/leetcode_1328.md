
+++
authors = ["Yasir"]
title = "Leetcode 1328: Break a Palindrome"
date = "2021-03-10"
description = "Solution to Leetcode 1328"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/break-a-palindrome/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        for(int i = 0; i < n / 2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};
{{< /highlight >}}

