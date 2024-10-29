
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2020-04-06"
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

{{< highlight cpp >}}
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

