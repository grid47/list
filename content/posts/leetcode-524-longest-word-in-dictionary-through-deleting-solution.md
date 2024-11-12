
+++
authors = ["grid47"]
title = "Leetcode 524: Longest Word in Dictionary through Deleting"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 524: Longest Word in Dictionary through Deleting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
        string ans;
        for(int i = 0; i < d.size(); i++) {
            
            int pi = 0, pj = 0;
            
            for(; pi < s.size() && pj < d[i].size(); pi++) {
                pj += s[pi] == d[i][pj];
            }
            
            if(pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/524.md" >}}
---
{{< youtube tvaZ8-WobKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #525: Contiguous Array](https://grid47.xyz/posts/leetcode-525-contiguous-array-solution/) |
| --- |
