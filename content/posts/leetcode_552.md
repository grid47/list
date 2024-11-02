
+++
authors = ["Crafted by Me"]
title = "Leetcode 552: Student Attendance Record II"
date = "2022-04-29"
description = "Solution to Leetcode 552"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/student-attendance-record-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<vector<int>>> mem;
    int mod = (int) 1e9 + 7;
    
    int dp(int idx, int a, int l) {
        if(idx == n) return l != 3 && a != 2;

        if(a >= 2 || l >= 3) return 0;

        if(mem[idx][a][l] != -1) return mem[idx][a][l];
        
        long ans = dp(idx + 1, a, 0) % mod + dp(idx + 1, a + 1, 0) % mod;

        if(l < 2) ans += dp(idx + 1, a, l + 1) % mod;

        return mem[idx][a][l] = ans % mod;
    }
    
    int checkRecord(int n) {
        this-> n = n;
        mem.resize(n + 1, vector<vector<int>>(3, vector<int>(4, -1)));
        return dp(0, 0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/552.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

