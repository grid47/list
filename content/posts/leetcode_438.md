
+++
authors = ["Crafted by Me"]
title = "Leetcode 438: Find All Anagrams in a String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 438: Find All Anagrams in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0), sc(26, 0);
        for(char x: p)
            pc[x-'a']++;
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i >= p.size()) {
                sc[s[i - p.size()] - 'a']--;
            }
            sc[s[i]-'a']++;
            if(sc == pc) ans.push_back(i - p.size() +1);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/438.md" >}}
---
{{< youtube G8xtZy0fDKg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #439: Ternary Expression Parser](https://grid47.xyz/posts/leetcode_439) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

