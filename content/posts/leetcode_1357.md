
+++
authors = ["Crafted by Me"]
title = "Leetcode 1357: Apply Discount Every n Orders"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1357: Apply Discount Every n Orders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-discount-every-n-orders/description/)

---

**Code:**

{{< highlight cpp >}}
class Cashier {
    int cnt, mod;
    double pct;
    unordered_map<int, int> tags;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0;
        mod = n;
        pct = (100 - discount)/ 100.0;
        for(int i = 0; i < products.size(); i++)
            tags[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        int ans = 0;
        for(int i = 0; i < product.size(); i++)
            ans += tags[product[i]] * amount[i];
        return cnt%mod? ans: ans * pct; 
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1357.md" >}}
---
{{< youtube A-PXwozdaCg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1358: Number of Substrings Containing All Three Characters](https://grid47.xyz/posts/leetcode_1358) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
