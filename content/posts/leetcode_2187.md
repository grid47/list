
+++
authors = ["Yasir"]
title = "Leetcode 2187: Minimum Time to Complete Trips"
date = "2018-11-02"
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

{{< highlight html >}}
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

