
+++
authors = ["Crafted by Me"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2017-03-06"
description = "In-depth solution and explanation for Leetcode 2798: Number of Employees Who Met the Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-employees-who-met-the-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for(int i = 0; i < hours.size(); i++)
            if(hours[i] >= target) cnt++;
        return cnt;
    }
};
{{< /highlight >}}


---


"| 2799: Count Complete Subarrays in an Array |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

