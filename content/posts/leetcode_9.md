
+++
authors = ["Crafted by Me"]
title = "Leetcode 9: Palindrome Number"
date = "2024-10-24"
description = "In-depth solution and explanation for Leetcode 9: Palindrome Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-number/description/)

---

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
---
{{< youtube yubRKwixN-U >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

