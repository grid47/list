
+++
authors = ["Crafted by Me"]
title = "Leetcode 2280: Minimum Lines to Represent a Line Chart"
date = "2017-08-05"
description = "Solution to Leetcode 2280"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLines(vector<vector<int>>& stk) {
        
        sort(stk.begin(), stk.end());
        
        int res = 1, n = stk.size();
        if (n < 2) return 0;

        for(int i = 2; i < n; i++) {
            long x1 = stk[i][0], x2 = stk[i - 1][0], x3 = stk[i - 2][0];
            long y1 = stk[i][1], y2 = stk[i - 1][1], y3 = stk[i - 2][1];
            
            long diff1 = (y3 - y2) * (x2 - x1);
            long diff2 = (y2 - y1) * (x3 - x2);
            
            if (diff1 != diff2) res++;
        }

        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

