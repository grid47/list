
+++
authors = ["Crafted by Me"]
title = "Leetcode 387: First Unique Character in a String"
date = "2023-10-12"
description = "In-depth solution and explanation for Leetcode 387: First Unique Character in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> mp;
        for(char x: s) mp[x]++;
        
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] == 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/387.md" >}}
---
{{< youtube nFiAUwTH0zY >}}
| Next : [LeetCode #388: Longest Absolute File Path](https://grid47.xyz/posts/leetcode_388) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

