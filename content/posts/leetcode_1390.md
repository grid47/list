
+++
authors = ["Crafted by Me"]
title = "Leetcode 1390: Four Divisors"
date = "2020-01-12"
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

