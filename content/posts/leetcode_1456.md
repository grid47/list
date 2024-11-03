
+++
authors = ["Crafted by Me"]
title = "Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length"
date = "2020-11-07"
description = "In-depth solution and explanation for Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                        0,0,0,0,1, 0,0,0,0,0, 
                        1,0,0,0,0, 0 };
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i = 0, cur = 0; i < s.size(); i++) {
            cur += vowels[s[i] - 'a'];
            if(i >= k) cur -= vowels[s[i-k] - 'a'];
            mx = max(cur, mx);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1456.md" >}}
---
{{< youtube tal8tKUr6dU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1457: Pseudo-Palindromic Paths in a Binary Tree](https://grid47.xyz/posts/leetcode_1457) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

