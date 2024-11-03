
+++
authors = ["Crafted by Me"]
title = "Leetcode 1016: Binary String With Substrings Representing 1 To N"
date = "2022-01-21"
description = "In-depth solution and explanation for Leetcode 1016: Binary String With Substrings Representing 1 To N in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n; i > n / 2; i--) {
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1016.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1017: Convert to Base -2](https://grid47.xyz/posts/leetcode_1017) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

