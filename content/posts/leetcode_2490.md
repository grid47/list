
+++
authors = ["Yasir"]
title = "Leetcode 2490: Circular Sentence"
date = "2018-01-03"
description = "Solution to Leetcode 2490"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-sentence/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.size();
        if((s[0]) != (s[n - 1]))
            return false;
        for(int i = 1; i < s.size() - 1; i++) {
            if(s[i] == ' ') {
                if((s[i - 1]) != (s[i + 1]))
                    return false;                
            }
        }
        return true;
    }
};
{{< /highlight >}}

