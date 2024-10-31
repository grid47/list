
+++
authors = ["Crafted by Me"]
title = "Leetcode 1725: Number Of Rectangles That Can Form The Largest Square"
date = "2020-02-11"
description = "Solution to Leetcode 1725"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:rectangles){
            int m=min(i[0],i[1]);
            ans=max(ans,m);
            mp[m]++;
        }
        
        return mp[ans];

    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

