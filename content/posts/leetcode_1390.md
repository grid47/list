
+++
authors = ["Crafted by Me"]
title = "Leetcode 1390: Four Divisors"
date = "2021-01-11"
description = "Solution to Leetcode 1390"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/four-divisors/description/)

---

**Code:**

{{< highlight cpp >}}


class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto n: nums) {
            int d = 0;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    if(d == 0) {
                        d = i;
                    } else {
                        d = 0;
                        break;
                    }
                }
            }
            if(d > 0 && d != n/d) {
                sum += 1 + n + d + n/d;
            }            
        }
        return sum;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

