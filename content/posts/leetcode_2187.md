
+++
authors = ["Crafted by Me"]
title = "Leetcode 2187: Minimum Time to Complete Trips"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2187: Minimum Time to Complete Trips in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-complete-trips/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long numberOfTripsForAGivenTime(vector<int> &a, long long int givenTime) {
        long long int totalTrips = 0;
        for(int &x : a) {
            long long int y = x;
            totalTrips += givenTime / y;
        }
        return totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1, high = 1e14;
        while(low < high) {
            long long int mid = low + (high - low) / 2;
            if(numberOfTripsForAGivenTime(time, mid) >= totalTrips) {
                high = mid;
            } else low = mid + 1;
        }
        return low;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2187.md" >}}
---
{{< youtube M5moLQ_6Xs4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2188: Minimum Time to Finish the Race](https://grid47.xyz/posts/leetcode_2188) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
