
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits"
date = "2018-06-01"
description = "Solution to Leetcode 2342"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        map<int, int> mp;
        
        int ans = -1;
        
        for(int x: nums) {
            int sum = 0;
            int tmp = x;
            while(tmp > 0) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            if(mp.count(sum)) {
                ans = max(ans, x + mp[sum]);
                mp[sum] = max(x, mp[sum]);
            } else {
                mp[sum] = x;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

