
+++
authors = ["grid47"]
title = "Leetcode 552: Student Attendance Record II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 552: Student Attendance Record II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
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
{{< youtube BPIJ5ROX0i4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #553: Optimal Division](https://grid47.xyz/posts/leetcode-553-optimal-division-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
