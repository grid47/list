
+++
authors = ["grid47"]
title = "Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day?"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "F4JpJIntzbQ"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/F4JpJIntzbQ/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1744.md" >}}
---
{{< youtube F4JpJIntzbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1748: Sum of Unique Elements](https://grid47.xyz/leetcode/solution-1748-sum-of-unique-elements/) |
| --- |
