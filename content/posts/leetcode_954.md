
+++
authors = ["Yasir"]
title = "Leetcode 954: Array of Doubled Pairs"
date = "2022-03-20"
description = "Solution to Leetcode 954"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-of-doubled-pairs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int, int> c;
        for(int i : arr)
            c[i]++;
        
        vector<int> keys;
        for(auto it: c)
            keys.push_back(it.first);
        
        sort(keys.begin(), keys.end(), [&](int a, int b){
            return abs(a) < abs(b);
        });
        
        for(int x: keys) {
            if(c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        
        return true;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

