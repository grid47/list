
+++
authors = ["Yasir"]
title = "Leetcode 1422: Maximum Score After Splitting a String"
date = "2020-12-06"
description = "Solution to Leetcode 1422"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxScore(string s) {
        int rightOnes = 0, leftZeroes = 0;
        for(char c: s)
            if(c=='1') rightOnes++;
        
        int score = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='0') leftZeroes++;
            else rightOnes--;
            score = max(score, leftZeroes + rightOnes);
        }
        return score;
    }
};
{{< /highlight >}}

