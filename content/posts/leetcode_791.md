
+++
authors = ["Yasir"]
title = "Leetcode 791: Custom Sort String"
date = "2022-08-28"
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

{{< highlight html >}}
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

