
+++
authors = ["Crafted by Me"]
title = "Leetcode 1422: Maximum Score After Splitting a String"
date = "2019-12-11"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

