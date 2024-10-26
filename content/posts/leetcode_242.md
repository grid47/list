
+++
authors = ["Yasir"]
title = "Leetcode 242: Valid Anagram"
date = "2024-02-28"
description = "Solution to Leetcode 242"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-anagram/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ch(26, 0);
        for(char x: s) ch[x - 'a']++;
        for(char x: t) ch[x - 'a']--;
        for(int x: ch) if(x != 0) return false;
        return true;
    }
};
{{< /highlight >}}

