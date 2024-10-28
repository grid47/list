
+++
authors = ["Yasir"]
title = "Leetcode 2347: Best Poker Hand"
date = "2018-05-27"
description = "Solution to Leetcode 2347"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-poker-hand/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int> m1;
        unordered_map<char,int> m2;
        for(auto i:ranks) m1[i]++;
        for(auto i:suits) m2[i]++;
        string ans="";
        for(auto i:m2){
            if(i.second==5){
                return "Flush";
            }
        }
        for(auto i:m1){
            if(i.second>=3)
            return "Three of a Kind";
            else if(i.second==2)
            ans="Pair";
        }

        return ans==""?"High Card":ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

