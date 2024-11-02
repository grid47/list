
+++
authors = ["Crafted by Me"]
title = "Leetcode 2600: K Items With the Maximum Sum"
date = "2016-09-19"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

