
+++
authors = ["grid47"]
title = "Leetcode 1386: Cinema Seat Allocation"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1386: Cinema Seat Allocation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Bit Manipulation"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1386.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1387: Sort Integers by The Power Value](https://grid47.xyz/posts/leetcode-1387-sort-integers-by-the-power-value-solution/) |
| --- |
