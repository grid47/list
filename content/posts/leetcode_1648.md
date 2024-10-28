
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1648: Sell Diminishing-Valued Colored Balls"
date = "2020-04-25"
description = "Solution to Leetcode 1648"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int maxProfit(vector<int>& inv, int orders) {
        
        
        long n = inv.size(), res = 0;
        
        sort(inv.rbegin(), inv.rend());
        
        for(int i = 0, col = 1; i < n && orders > 0; i++, col++) {
            long cur = inv[i], prv = i + 1 < n? inv[i + 1]: 0;
            long depth = min((long)orders/col, (long)cur - prv);
            orders -= depth * col;
            
        res = (res + ((cur * (cur + 1) - (cur - depth) * (cur - depth + 1)) / 2 * col)) % mod;
                  
            if(cur - prv > depth) {
                res = (res + orders * (cur - depth)) % mod;
                break;
            }
        }
        
        /*
            There is a value k, for which all the balls above this value are sold.
            
        */
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

