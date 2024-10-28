
+++
authors = ["Yasir"]
title = "Leetcode 2523: Closest Prime Numbers in Range"
date = "2017-12-02"
description = "Solution to Leetcode 2523"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool seive[1000001] = {};
    vector<int> p = {2};
    vector<int> closestPrimes(int left, int right) {
        
        for(int i = 3; i < 1000001; i += 2) {
            if(!seive[i]) {
                p.push_back(i);
                for (long long j = (long long) i * i; j < 1000001; j += i) {
                    seive[j] = true;
                }
            }
        }
        
        int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
        
        for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
            if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
                n1 = p[i];
                n2 = p[i + 1];
                if(n2 - n1 < 3) break;
            }
        }
        return {n1, n2};
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

