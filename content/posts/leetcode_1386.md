
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1386: Cinema Seat Allocation"
date = "2021-01-14"
description = "Solution to Leetcode 1386"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cinema-seat-allocation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2;
        unordered_map<int, char> m;
        for(auto r: reservedSeats)
            if(r[1] > 1 && r[1] < 10)
                m[r[0]] |= 1 << (r[1] - 2);
        
        for(auto [row, seats]: m) {
            int left  = seats & 0b11110000;
            int mid   = seats & 0b00111100;
            int right = seats & 0b00001111;
            ans -= left && mid && right ? 2 : 1;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

