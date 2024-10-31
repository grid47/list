
+++
authors = ["Crafted by Me"]
title = "Leetcode 2571: Minimum Operations to Reduce an Integer to 0"
date = "2017-10-18"
description = "Solution to Leetcode 2571"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int dp(int n) {
        if(n == 0) return 0;
        // cout << n << " " ;
        int ans = 0;
        if((n & 1) == 0) {
            ans = dp(n >> 1);
        } else {
            if(((n >> 1) & 1)== 1) {
            // if(n == 5) cout << "'" << n<< "'";                
                n += 1;
                // while((n & 1) == 0) n >>= 1;
                ans = 1 + dp(n);
            } else {
                ans = 1 + dp(n >> 1);
            }
        }
        return ans;
    }
    
    int minOperations(int n) {
        // aggregate consecutive ones
        // turn of one
        return dp(n);
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

