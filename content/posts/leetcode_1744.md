
+++
authors = ["Yasir"]
title = "Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day?"
date = "2020-01-20"
description = "Solution to Leetcode 1744"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<bool> canEat(vector<int>& nums, vector<vector<int>>& q) {
        typedef long long ll;
        vector<ll> cnt(nums.size() +1, 0);
        
        for(int i = 1; i < nums.size() +1; i++)
            cnt[i] += cnt[i - 1] + nums[i -1];
        
        vector<bool> res;
        for(auto & v : q) {
            ll type = v[0], day = v[1], cap = v[2];
            ll mn = cnt[type] / cap;
            ll mx = cnt[type + 1] - 1;

if (mn <= day && day <= mx) {
    res.push_back(true); }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

