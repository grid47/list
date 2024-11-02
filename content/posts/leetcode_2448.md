
+++
authors = ["Crafted by Me"]
title = "Leetcode 2448: Minimum Cost to Make Array Equal"
date = "2017-02-18"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

