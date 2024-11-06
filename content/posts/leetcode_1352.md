
+++
authors = ["Crafted by Me"]
title = "Leetcode 1352: Product of the Last K Numbers"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1353: Maximum Number of Events That Can Be Attended](https://grid47.xyz/posts/leetcode_1353) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
