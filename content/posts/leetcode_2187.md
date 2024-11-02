
+++
authors = ["Crafted by Me"]
title = "Leetcode 2187: Minimum Time to Complete Trips"
date = "2018-11-07"
description = "Solution to Leetcode 2187"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

