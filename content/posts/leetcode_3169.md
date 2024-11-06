
+++
authors = ["Crafted by Me"]
title = "Leetcode 3169: Count Days Without Meetings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3169: Count Days Without Meetings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-days-without-meetings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) {
        int net = days;
        int n = mt.size();
        sort(mt.begin(), mt.end());
        vector<int> tuned;
        vector<int> pt = mt[0];
        if(n == 1) return net - (pt[1] - pt[0] + 1);
        for(int i = 1; i < n; i++) {
            if (mt[i][0] <= pt[1])
                pt[1] = max(pt[1], mt[i][1]);
            else {
                net -= pt[1] - pt[0] + 1;
                pt = mt[i];
            }
            if(i + 1 == n) net -= pt[1] - pt[0] + 1;
        }
        return net;
    }
};
{{< /highlight >}}


---
{{< youtube 72-mDiuXbLk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3170: Lexicographically Minimum String After Removing Stars](https://grid47.xyz/posts/leetcode_3170) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
