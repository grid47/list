
+++
authors = ["Crafted by Me"]
title = "Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day?"
date = "2020-01-24"
description = "In-depth solution and explanation for Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


| Next : [LeetCode #1745: Palindrome Partitioning IV](grid47.xyz/leetcode_1745) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

