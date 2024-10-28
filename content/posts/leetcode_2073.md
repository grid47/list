
+++
authors = ["Yasir"]
title = "Leetcode 2073: Time Needed to Buy Tickets"
date = "2019-02-25"
description = "Solution to Leetcode 2073"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int res = 0, key = nums[k];
        for(int i = 0; i < nums.size(); i++) {
          res += min(key - (i > k), nums[i]);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

