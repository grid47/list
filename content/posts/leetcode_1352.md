
+++
authors = ["Yasir"]
title = "Leetcode 1352: Product of the Last K Numbers"
date = "2021-02-14"
description = "Solution to Leetcode 1352"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/product-of-the-last-k-numbers/description/)

---

**Code:**

{{< highlight html >}}
class ProductOfNumbers {
    vector<long long> p;
public:
    ProductOfNumbers() {
        p = {1};
    }
    
    void add(int num) {
        if(num > 0) {
            p.push_back(p.back() * num);
        } else {
            p = {1};            
        }

    }
    
    int getProduct(int k) {
        int n = p.size();
        return k < n ? p[n - 1] / p[n - k - 1]: 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
{{< /highlight >}}

