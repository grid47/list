
+++
authors = ["grid47"]
title = "Leetcode 2438: Range Product Queries of Powers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2438: Range Product Queries of Powers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/range-product-queries-of-powers/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2438.md" >}}
---
{{< youtube BGr1RD2mxhs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2439: Minimize Maximum of Array](https://grid47.xyz/posts/leetcode-2438-range-product-queries-of-powers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
