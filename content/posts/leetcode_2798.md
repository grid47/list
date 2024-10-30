
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2798: Number of Employees Who Met the Target"
date = "2017-03-04"
description = "Solution to Leetcode 2798"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

