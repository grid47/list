
+++
authors = ["Yasir"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2020-04-05"
description = "Solution to Leetcode 1668"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-repeating-substring/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

