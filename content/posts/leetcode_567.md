
+++
authors = ["Crafted by Me"]
title = "Leetcode 567: Permutation in String"
date = "2023-04-15"
description = "In-depth solution and explanation for Leetcode 567: Permutation in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutation-in-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> p1(26, 0), p2(26, 0);
        for(char x: s1) p1[x-'a']++;
        for(int i = 0; i < s2.size(); i++) {
            if(i >= s1.size()) p2[s2[i - s1.size()] - 'a']--;
            p2[s2[i] - 'a']++;
            if(p1 == p2) return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/567.md" >}}
---
{{< youtube quSfR-uwkZU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #568: Maximum Vacation Days](https://grid47.xyz/posts/leetcode_568) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

