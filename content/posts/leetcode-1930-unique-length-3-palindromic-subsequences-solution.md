
+++
authors = ["grid47"]
title = "Leetcode 1930: Unique Length-3 Palindromic Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1930: Unique Length-3 Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPalindromicSubsequence(string num) {
        int n = num.size(), res = 0;        
        vector<int> fst(26,n), lst(26,0);
        for(int i = 0; i < n; i++) {
            fst[num[i]-'a']= min(fst[num[i]-'a'], i);
            lst[num[i]-'a'] = i;
        }
        for(int i = 0; i < 26; i++) {
if(fst[i] < lst[i]) res += unordered_set<char>(num.begin() + fst[i] + 1, num.begin() + lst[i]).size();
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1930.md" >}}
---
{{< youtube 3THUt0vAFLU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1931: Painting a Grid With Three Different Colors](https://grid47.xyz/posts/leetcode-1931-painting-a-grid-with-three-different-colors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
