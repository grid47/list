
+++
authors = ["Yasir"]
title = "Leetcode 2486: Append Characters to String to Make Subsequence"
date = "2018-01-07"
description = "Solution to Leetcode 2486"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for(int i = 0; i < s.size() && j < t.size(); i++) {
            j += s[i] == t[j];
        }
        return t.size()-j;
    }
};
{{< /highlight >}}

