
+++
authors = ["Yasir"]
title = "Leetcode 1816: Truncate Sentence"
date = "2019-11-08"
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

{{< highlight html >}}
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

