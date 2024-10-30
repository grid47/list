
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 9: Palindrome Number"
date = "2024-10-22"
description = "Solution to Leetcode 9"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-number/description/)

---
{{< youtube yubRKwixN-U >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long int y = x, z = 0;
        while(x) {
            z = z * 10 + x % 10;
            x /= 10;
        }
        return y == z;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/9.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

