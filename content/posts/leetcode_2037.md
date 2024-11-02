
+++
authors = ["Crafted by Me"]
title = "Leetcode 2037: Minimum Number of Moves to Seat Everyone"
date = "2018-04-05"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

