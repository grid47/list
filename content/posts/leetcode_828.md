
+++
authors = ["Yasir"]
title = "Leetcode 828: Count Unique Characters of All Substrings of a Given String"
date = "2022-07-23"
description = "Solution to Leetcode 828"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    int uniqueLetterString(string s) {

        vector<vector<int>> idx(26, vector<int>(2, -1));
        
        int n = s.size();
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            res += (i - idx[c][1]) * (idx[c][1] - idx[c][0]);
            idx[c][0] = idx[c][1];
            idx[c][1] = i;
        }
        
        for(int i = 0; i < 26; i++)
            res += (n - idx[i][1]) * (idx[i][1] - idx[i][0]);
        
        return res;
    }
};
{{< /highlight >}}

