
+++
authors = ["Crafted by Me"]
title = "Leetcode 1880: Check if Word Equals Summation of Two Words"
date = "2018-09-09"
description = "Solution to Leetcode 1880"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first=0,second=0,target=0;
        for(int i=0;i<firstWord.size();i++)
            first=first*10 + (firstWord[i]-'a');
        
        for(int i=0;i<secondWord.size();i++)
            second=second*10 +(secondWord[i]-'a');
        
        for(int i=0;i<targetWord.size();i++)
            target=target*10 +(targetWord[i]-'a');
        
        
        return first+second == target;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

