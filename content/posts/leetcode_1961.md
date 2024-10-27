
+++
authors = ["Yasir"]
title = "Leetcode 1961: Check If String Is a Prefix of Array"
date = "2019-06-16"
description = "Solution to Leetcode 1961"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int k = 0, l = 0, i = 0;
        for(i = 0; i < s.size() && k < w.size(); i++) {
            
            if(s[i] != w[k][l]) return false;
            
            l++;
            
            if(l == w[k].size()) {
                k++;
                l = 0;
            }
        }
        if(i != s.size()) return false;
        return (l == 0);
    }
};
{{< /highlight >}}

