
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1109: Corporate Flight Bookings"
date = "2021-10-17"
description = "Solution to Leetcode 1109"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/corporate-flight-bookings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int m) {

        vector<int> ans(m, 0);
        for(auto& v: bookings) {
            ans[v[0] - 1] += v[2];
            if(v[1] < m) ans[v[1]] -= v[2];
        }

        for(int j = 1; j < m; j++)
            ans[j] += ans[j-1];

        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

