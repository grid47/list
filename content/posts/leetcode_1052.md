
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1052: Grumpy Bookstore Owner"
date = "2021-12-12"
description = "Solution to Leetcode 1052"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/grumpy-bookstore-owner/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {

        int res = 0;
        int n = cust.size();
        vector<int> mins(n, 0), cs(n, 0);
            
        for(int i = 0; i < n; i++) {
            if(i < min)
            mins[0] += cust[i];
            else
            mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];
            
            if(i == 0) cs[i] = gm[i] == 0 ? cust[i]: 0;
            else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i]:0);
        }
        // for(int i = 0; i < n; i++)
        //     cout << mins[i] << " ";
        // cout << "\n";
        // for(int i = 0; i < n; i++)
        //     cout << cs[i] << " ";
        for(int i = 0; i <= n - min; i++) {
            int ans = (i > 0? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);                
            res = max(res, ans); 
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

