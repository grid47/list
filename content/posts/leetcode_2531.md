
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2531: Make Number of Distinct Characters Equal"
date = "2017-11-24"
description = "Solution to Leetcode 2531"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isItPossible(string w1, string w2) {
        
        map<char, int> ma1, ma2;
        for(int x: w1)
            ma1[x]++;
        for(int x: w2)
            ma2[x]++;
        
        for(auto it1: ma1) {
            for(auto it2: ma2) {
                map<char, int> d1 = ma1, d2 = ma2;
                d1[it2.first]++;
                d2[it1.first]++;
                
                d1[it1.first]--;
                d2[it2.first]--;
                
                if(d1[it1.first] == 0)
                    d1.erase(it1.first);
                if(d2[it2.first] == 0)
                    d2.erase(it2.first);
                
                if(d1.size() == d2.size()) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

