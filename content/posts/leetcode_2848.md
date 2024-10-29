
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2848: Points That Intersect With Cars"
date = "2017-01-12"
description = "Solution to Leetcode 2848"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/points-that-intersect-with-cars/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
    vector<int> v(102, 0);
    int ans = 0;
    for(auto n: nums){
        for(int i = n[0]; i <= n[1]; ++i) v[i-1]++;
    }
    for(auto e: v){
        if(e) ans++;
    }
    return ans;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

