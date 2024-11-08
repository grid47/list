
+++
authors = ["grid47"]
title = "Leetcode 2347: Best Poker Hand"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2348: Number of Zero-Filled Subarrays](https://grid47.xyz/posts/leetcode_2348) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
