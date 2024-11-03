
+++
authors = ["Crafted by Me"]
title = "Leetcode 424: Longest Repeating Character Replacement"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 424: Longest Repeating Character Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0, mx = 0;
        for(int i =  0; i < s.size(); i++) {
            ma[s[i]]++;
            mx = max(mx, ma[s[i]]);
            if(i - j + 1 > mx + k) {
                ma[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/424.md" >}}
---
{{< youtube tkNWKvxI3mU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #425: Word Squares](https://grid47.xyz/posts/leetcode_425) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

