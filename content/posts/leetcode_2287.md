
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2287: Rearrange Characters to Make Target String"
date = "2018-07-26"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

