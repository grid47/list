
+++
authors = ["grid47"]
title = "Leetcode 2347: Best Poker Hand"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2347: Best Poker Hand in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-poker-hand/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2347.md" >}}
---
{{< youtube 6BijC5dBUOA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2348: Number of Zero-Filled Subarrays](https://grid47.xyz/posts/leetcode-2348-number-of-zero-filled-subarrays-solution/) |
| --- |
