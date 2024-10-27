
+++
authors = ["Yasir"]
title = "Leetcode 2037: Minimum Number of Moves to Seat Everyone"
date = "2019-04-01"
description = "Solution to Leetcode 2037"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int res = 0;
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
        
        return res;
    }
};
{{< /highlight >}}

