
+++
authors = ["Crafted by Me"]
title = "Leetcode 1328: Break a Palindrome"
date = "2020-03-14"
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

{{< highlight cpp >}}
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


---
{{< youtube B5v5rDR7c9A >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

