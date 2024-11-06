
+++
authors = ["Crafted by Me"]
title = "Leetcode 539: Minimum Time Difference"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 539: Minimum Time Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinDifference(vector<string>& time) {
        
        sort(time.begin(), time.end());
        
        int n = time.size(), mindiff = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int diff = abs(timeDiff(time[(i - 1 +n)%n], time[i]));
            
            diff = min(diff, 1440 - diff); // 1440 = 24h in minutes
            mindiff = min(mindiff, diff);
        }
        
        return mindiff;
    }
    
    int timeDiff(string t1, string t2) {
        // cout << t1 << t2;
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/539.md" >}}
---
{{< youtube LVBDzeUmNIQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #540: Single Element in a Sorted Array](https://grid47.xyz/posts/leetcode_540) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
