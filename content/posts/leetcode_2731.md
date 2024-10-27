
+++
authors = ["Yasir"]
title = "Leetcode 2731: Movement of Robots"
date = "2017-05-07"
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

{{< highlight html >}}
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

