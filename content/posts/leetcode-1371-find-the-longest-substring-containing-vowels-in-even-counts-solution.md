
+++
authors = ["grid47"]
title = "Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1371: Find the Longest Substring Containing Vowels in Even Counts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> id = {
            {'a' , 1},
            {'e' , 2},
            {'i' , 3},
            {'o' , 4},
            {'u' , 5},
            };
        int res = 0, msk = 0;
        map<int, int> mp;
 
        mp[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            int x = id[s[i]];
            
            if(x != 0)
            msk ^= (1 << x);
            if(mp.count(msk)) {
            res = max(res, i - mp[msk]);
                }
            else {
            mp[msk] = i;}
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1371.md" >}}
---
{{< youtube o17MBWparrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1372: Longest ZigZag Path in a Binary Tree](https://grid47.xyz/posts/leetcode-1372-longest-zigzag-path-in-a-binary-tree-solution/) |
| --- |
