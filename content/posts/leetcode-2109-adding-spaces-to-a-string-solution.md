
+++
authors = ["grid47"]
title = "Leetcode 2109: Adding Spaces to a String"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2110: Number of Smooth Descent Periods of a Stock](https://grid47.xyz/posts/leetcode-2109-adding-spaces-to-a-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
