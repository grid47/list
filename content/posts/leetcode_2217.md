
+++
authors = ["Crafted by Me"]
title = "Leetcode 2217: Find Palindrome With Fixed Length"
date = "2018-10-07"
description = "Solution to Leetcode 2217"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-palindrome-with-fixed-length/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long reverse(long long n, int skip) {
        long long res = 0;
        for(n = skip?n/10: n; n > 0; n/=10)
            res = res * 10 + n % 10;
        return res;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int sz) {
        vector<long long> ans;
        long long start = pow(10, (sz + 1)/2-1), end = pow(10, (sz + 1)/2), mul= pow(10, sz/2);
        for(auto q: queries)
            if(start + q > end)
                ans.push_back(-1);
            else {
                long long res = (start + q - 1) * mul + reverse(start + q - 1, sz % 2);
                ans.push_back(res);
            }
        
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

