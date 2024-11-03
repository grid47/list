
+++
authors = ["Crafted by Me"]
title = "Leetcode 2734: Lexicographically Smallest String After Substring Operation"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2734: Lexicographically Smallest String After Substring Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while(i < s.size() && s[i] == 'a') i++;
        if(i >= s.size()) { s[s.size()-1] = 'z'; return s; }
        while(i < s.size() && s[i] != 'a') { s[i]--; i++; }
        return s;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2735: Collecting Chocolates](https://grid47.xyz/posts/leetcode_2735) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

