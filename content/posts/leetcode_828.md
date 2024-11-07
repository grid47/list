
+++
authors = ["Crafted by Me"]
title = "Leetcode 828: Count Unique Characters of All Substrings of a Given String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 828: Count Unique Characters of All Substrings of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int uniqueLetterString(string s) {

        vector<vector<int>> idx(26, vector<int>(2, -1));
        
        int n = s.size();
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            res += (i - idx[c][1]) * (idx[c][1] - idx[c][0]);
            idx[c][0] = idx[c][1];
            idx[c][1] = i;
        }
        
        for(int i = 0; i < 26; i++)
            res += (n - idx[i][1]) * (idx[i][1] - idx[i][0]);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/828.md" >}}
---
{{< youtube icdH-hoxpfs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #831: Masking Personal Information](https://grid47.xyz/posts/leetcode_831) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
