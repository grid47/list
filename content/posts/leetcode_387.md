
+++
authors = ["Yasir"]
title = "Leetcode 387: First Unique Character in a String"
date = "2023-10-06"
description = "Solution to Leetcode 387"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> mp;
        for(char x: s) mp[x]++;
        
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] == 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}

