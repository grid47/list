
+++
authors = ["Crafted by Me"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-06-30"
description = "In-depth solution and explanation for Leetcode 125: Valid Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube jJXJ16kPFWg >}}

| Next : [LeetCode #126: Word Ladder II](grid47.xyz/leetcode_126) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

