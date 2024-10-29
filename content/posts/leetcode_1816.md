
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1816: Truncate Sentence"
date = "2019-11-10"
description = "Solution to Leetcode 1816"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/truncate-sentence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =0;
        string ans="";
        for(auto x:s)
        {
            if(x==' ')
                count++;
            if(count==k)
                break;
            ans+=x;
        }
        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

