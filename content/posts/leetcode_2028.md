
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2028: Find Missing Observations"
date = "2019-04-12"
description = "Solution to Leetcode 2028"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-missing-observations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<map<int, bool>> memo;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        
        int sum = 0;
        for(int i = 0; i < m; i++)
            sum += rolls[i];
        
        int net = mean * (m + n);
        
        sum = net - sum;
        
        // create an array of size n with sum = sum and elements 1 - 6
        
        if(sum < n || sum > 6 * n) return vector<int>{};

        int x = sum / n, rem = sum % n;
        vector<int> res(n, x);
        
        for(int i = 0; i < rem; i++) {
            res[i]++;
        }

        return res;
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
