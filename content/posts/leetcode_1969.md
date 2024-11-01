
+++
authors = ["Crafted by Me"]
title = "Leetcode 1969: Minimum Non-Zero Product of the Array Elements"
date = "2019-06-13"
description = "Solution to Leetcode 1969"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long mod = 1000000007;
    
    long long expn(long long n, long long p) {
        if(p == 0) return 1;
        if(p == 1) return n%mod;
        if(p % 2 == 0) {
            long long ans = expn(n, p / 2);
            return ((ans ) * (ans )) % mod;
        } else {
            long long ans = expn(n, p / 2);
            ans = ((ans ) * (ans )) % mod;
            return (ans * (n % mod)) % mod;
        }
        return 0;
    }

    
    int minNonZeroProduct(int p) {
        long long val = pow(2, p);
        val--;
        long long ans = expn(val-1, val/2);
        return ans * (val %mod)% mod;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

