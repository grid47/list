
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1854: Maximum Population Year"
date = "2019-10-02"
description = "Solution to Leetcode 1854"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-population-year/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;
            sum[v[0] - 1950]++;
        }
        
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {
                yr = i + 1950;
                mx = sum[i];
            }
        }
        return yr;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

