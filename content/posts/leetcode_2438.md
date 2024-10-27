
+++
authors = ["Yasir"]
title = "Leetcode 2438: Range Product Queries of Powers"
date = "2018-02-24"
description = "Solution to Leetcode 2438"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/range-product-queries-of-powers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        
        vector<long long> pow;
        long long init = 1;
        while(n) {
            if(n & 1) pow.push_back(init);
            init *= 2;
            n /= 2;
        }
        
        
        
        vector<int> ans;
        for(int i = 0; i < q.size(); i++) {
            int tmp = pow[q[i][0]];
            for(int j = q[i][0] + 1; j <= q[i][1]; j++)
                tmp = (tmp * pow[j]) % mod;
            ans.push_back(tmp);
        }
        return ans;
    }
};
{{< /highlight >}}

