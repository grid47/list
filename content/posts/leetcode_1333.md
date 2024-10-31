
+++
authors = ["Crafted by Me"]
title = "Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance"
date = "2021-03-09"
description = "Solution to Leetcode 1333"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
        
        vector<vector<int>> ans;
        
        for(auto r: rest) {
            if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
                ans.push_back({r[0], r[1]});
            }
        }
        
        sort(ans.begin(), ans.end(), cmp);
        
        vector<int> res;
        for(auto x: ans) {
            res.push_back(x[0]);
        }
        return res;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

