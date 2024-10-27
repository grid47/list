
+++
authors = ["Yasir"]
title = "Leetcode 1357: Apply Discount Every n Orders"
date = "2021-02-09"
description = "Solution to Leetcode 1357"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-discount-every-n-orders/description/)

---

**Code:**

{{< highlight html >}}
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

