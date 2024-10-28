
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 791: Custom Sort String"
date = "2022-08-30"
description = "Solution to Leetcode 791"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/custom-sort-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string customSortString(string o, string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0; i < o.size(); i++)
            mp[o[i]] = i + 1;
        
        sort(s.begin(), s.end(), [&](char a, char b) {
            return mp[a] < mp[b];
        });
        
        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

