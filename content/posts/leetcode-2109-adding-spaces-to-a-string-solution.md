
+++
authors = ["grid47"]
title = "Leetcode 2109: Adding Spaces to a String"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2109: Adding Spaces to a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/adding-spaces-to-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        string res = "";
        for(int idx : spaces) {
            while(i < idx) res += s[i++];
            if(i == idx) res += ' ';
        }
        while(i < s.size()) res += s[i++];        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2109.md" >}}
---
{{< youtube HhsyccqLHDw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2110: Number of Smooth Descent Periods of a Stock](https://grid47.xyz/posts/leetcode-2110-number-of-smooth-descent-periods-of-a-stock-solution/) |
| --- |
