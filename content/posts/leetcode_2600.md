
+++
authors = ["Yasir"]
title = "Leetcode 2600: K Items With the Maximum Sum"
date = "2017-09-15"
description = "Solution to Leetcode 2600"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-items-with-the-maximum-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
        int sum = 0;
        sum += min(one, k);
        k -= min(one, k);
        if(k > 0) {
            k -= min(zero, k);
        }
        if(k > 0) {
            sum -= min(neg, k);
            k -= min(neg, k);
        }
        return sum;
    }
};
{{< /highlight >}}

