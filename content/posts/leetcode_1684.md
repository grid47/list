
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1684: Count the Number of Consistent Strings"
date = "2020-03-20"
description = "Solution to Leetcode 1684"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool mp[26] = {};
        for (char c: allowed) mp[c - 'a'] = true;
        for (string word: words) {
            for (char c: word) if (!mp[c - 'a']) {
                res--;
                break;
            }
        }
        return res;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

