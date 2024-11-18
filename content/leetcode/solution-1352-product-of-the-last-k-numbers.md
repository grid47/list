
+++
authors = ["grid47"]
title = "Leetcode 1352: Product of the Last K Numbers"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1352: Product of the Last K Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Design","Queue","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/product-of-the-last-k-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1352.md" >}}
---
{{< youtube fH1WYQCcMd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1353: Maximum Number of Events That Can Be Attended](https://grid47.xyz/leetcode/solution-1353-maximum-number-of-events-that-can-be-attended/) |
| --- |
