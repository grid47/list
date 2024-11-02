
+++
authors = ["Crafted by Me"]
title = "Leetcode 3110: Score of a String"
date = "2015-04-28"
description = "Solution to Leetcode 3110"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-of-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum+=abs(s[i]-s[i+1]);
        }
        return sum;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

