
+++
authors = ["Crafted by Me"]
title = "Leetcode 1599: Maximum Profit of Operating a Centennial Wheel"
date = "2020-06-17"
description = "In-depth solution and explanation for Leetcode 1599: Maximum Profit of Operating a Centennial Wheel in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
        
        /*
        
        4gondolas
        couter clockwise
        running cost
        
        */

        int n = cust.size();
        int wait = 0;
        int profit = 0, rot = 0;
        int mx = INT_MIN;
        int idx = 0;
        while(idx < n || wait > 0) {
            wait += idx < n? cust[idx]:0;
            // cout << wait << " ";
            if(wait > 4) {
                profit += 4 * boardingCost - runningCost;
                wait -= 4;
            } else if(wait > 0) {
                profit += wait * boardingCost - runningCost;
                wait = 0;
            }

            if(mx < profit) {
                mx = profit;
                rot = idx + 1;
            }
            idx++;
        }
        return mx <= 0? -1: rot;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1600: Throne Inheritance](https://grid47.xyz/posts/leetcode_1600) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

