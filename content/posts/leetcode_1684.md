
+++
authors = ["Yasir"]
title = "Leetcode 1684: Count the Number of Consistent Strings"
date = "2020-03-19"
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

{{< highlight html >}}
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

