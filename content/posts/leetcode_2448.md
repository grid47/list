
+++
authors = ["Yasir"]
title = "Leetcode 2448: Minimum Cost to Make Array Equal"
date = "2018-02-14"
description = "Solution to Leetcode 2448"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    long long fn(vector<int>& nums, vector<int>& cost, int x) {
        long long res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res += (long long)abs(nums[i] - x) * cost[i];
        }
        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int l = nums[0], r = nums[0];
        for(int x: nums) {
            l = min(x, l);
            r = max(x, r);
        }
        long long ans = fn(nums, cost, nums[0]);
        while(l <= r) {
            long long mid   = l + (r - l + 1) / 2;
            long long y1    = fn(nums, cost, mid    );
            long long y2    = fn(nums, cost, mid + 1);
            ans = min(y1, y2);
            if(y1 < y2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

