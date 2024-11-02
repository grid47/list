
+++
authors = ["Crafted by Me"]
title = "Leetcode 1109: Corporate Flight Bookings"
date = "2020-10-19"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

