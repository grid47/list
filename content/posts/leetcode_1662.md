
+++
authors = ["Crafted by Me"]
title = "Leetcode 1662: Check If Two String Arrays are Equivalent"
date = "2019-04-15"
description = "Solution to Leetcode 1662"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1)
            a += x;
        for(auto x:word2)
            b += x;
       
        if(a == b)
            return 1;
        
        return 0;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

