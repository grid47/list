
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2731: Movement of Robots"
date = "2017-05-08"
description = "Solution to Leetcode 2731"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/movement-of-robots/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i = 0; i < nums.size(); i++) {
            if(s[i] == 'L') nums[i] -= d;
            else nums[i] += d;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0, dist = 0, mod = (int) 1e9 + 7;
        for(int i = 1; i < n; i++) {
            dist += ((long)nums[i] - nums[i - 1]) * (i);
            ans = (ans + dist) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

