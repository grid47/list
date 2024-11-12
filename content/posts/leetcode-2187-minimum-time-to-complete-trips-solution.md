
+++
authors = ["grid47"]
title = "Leetcode 2187: Minimum Time to Complete Trips"
date = "2024-04-02"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2190: Most Frequent Number Following Key In an Array](https://grid47.xyz/posts/leetcode-2190-most-frequent-number-following-key-in-an-array-solution/) |
| --- |
