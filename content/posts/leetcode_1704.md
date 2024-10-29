
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1704: Determine if String Halves Are Alike"
date = "2020-03-01"
description = "Solution to Leetcode 1704"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-string-halves-are-alike/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool halvesAreAlike(string s) {
        int t=0;
        for(int i=0;i<s.size();i++)
        {   
            s[i]=tolower(s[i]);
            if(i<s.size()/2)
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                      t++;                  // counting for the first half of the string
            }
            else
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                     t--;            // reducing the count if occures in second half of the string 
            }     
        } 
       return (t==0);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

