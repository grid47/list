
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 524: Longest Word in Dictionary through Deleting"
date = "2023-05-25"
description = "Solution to Leetcode 524"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
