
+++
authors = ["Crafted by Me"]
title = "Leetcode 2594: Minimum Time to Repair Cars"
date = "2017-09-26"
description = "In-depth solution and explanation for Leetcode 2594: Minimum Time to Repair Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-repair-cars/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(vector<int> &ranks, long long time, int cars) {
        long long cnt = 0;
        if(time == 0) return false;
        for(int i = 0; i < ranks.size(); i++) {
            cnt += (long long) sqrt(time/ranks[i]);
            
            if(cnt >= cars) return true;
        }
        
        return cnt >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int mx = ranks[ranks.size() - 1];
        long long l = 0, r = LLONG_MAX - 100;
        long long ans = r;
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if(can(ranks, mid, cars)) {
                ans= mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2595: Number of Even and Odd Bits](grid47.xyz/leetcode_2595) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

