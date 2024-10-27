
+++
authors = ["Yasir"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2018-05-22"
description = "Solution to Leetcode 2351"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1)return c;
        }
        return 'a';
    }
};
{{< /highlight >}}

