
+++
authors = ["Crafted by Me"]
title = "Leetcode 2561: Rearranging Fruits"
date = "2017-10-28"
description = "Solution to Leetcode 2561"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearranging-fruits/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, int> c1;
        
        for(int x: b1) c1[x]++;
        for(int x: b2) c1[x]--;
        
        long long res = 0;
        
        vector<int> swaps;
        for(auto [k1, v1]: c1){
            if(v1 % 2) return -1;

            for(int i = 0; i < abs(v1) / 2; i++)
                swaps.push_back(k1);
        }
        
        int mn = c1.begin()->first;
        
        for(int i = 0; i < swaps.size() / 2; i++)
            res += min(swaps[i], mn * 2);

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

