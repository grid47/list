
+++
authors = ["Crafted by Me"]
title = "Leetcode 2580: Count Ways to Group Overlapping Ranges"
date = "2016-10-09"
description = "Solution to Leetcode 2580"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countWays(vector<vector<int>>& range) {
        sort(range.begin(), range.end());
        int n = range.size();
        
        int mod = (int) 1e9 + 7;        
        int next = range[0][1];
        long cnt = 2;
        for(int i = 0; i < n; i++) {
            if(range[i][0] <= next) {
                next = max(next, range[i][1]);
                continue;
            }
            cnt = (cnt * 2) % mod;
            next = range[i][1];
        }

        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

