
+++
authors = ["grid47"]
title = "Leetcode 1930: Unique Length-3 Palindromic Subsequences"
date = "2024-04-28"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1935: Maximum Number of Words You Can Type](https://grid47.xyz/leetcode/solution-1935-maximum-number-of-words-you-can-type/) |
| --- |
