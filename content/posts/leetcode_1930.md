
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1930: Unique Length-3 Palindromic Subsequences"
date = "2019-07-19"
description = "Solution to Leetcode 1930"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

