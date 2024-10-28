
+++
authors = ["Yasir"]
title = "Leetcode 3110: Score of a String"
date = "2016-04-24"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

