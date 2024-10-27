
+++
authors = ["Yasir"]
title = "Leetcode 2287: Rearrange Characters to Make Target String"
date = "2018-07-25"
description = "Solution to Leetcode 2287"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> targetFreq ; 
        for(auto a : target) {
             targetFreq[a] ++;
        }
        unordered_map<char , int> sentFreq ; 
        for(auto a : s) {
            sentFreq[a] ++ ; 
        }
        int mn = INT_MAX  ; 
        for(auto a : targetFreq ) {
             mn = min(mn , sentFreq[a.first]/a.second); 
        }
        return mn ; 
    }
};
{{< /highlight >}}

