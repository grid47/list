
+++
authors = ["Crafted by Me"]
title = "Leetcode 1701: Average Waiting Time"
date = "2020-03-07"
description = "Solution to Leetcode 1701"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-waiting-time/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        
        int cur = cust[0][0];
        
        double n = cust.size();
        double sum = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(cur > cust[i][0])
            cur += cust[i][1];
            else
            cur = cust[i][0] + cust[i][1];
            
            sum += cur - cust[i][0];
            
        }
        
        return sum / n;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

