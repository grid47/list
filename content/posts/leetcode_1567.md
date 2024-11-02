
+++
authors = ["Crafted by Me"]
title = "Leetcode 1567: Maximum Length of Subarray With Positive Product"
date = "2020-07-19"
description = "Solution to Leetcode 1567"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, positive = 0, negative = 0;
        for(int x : nums) {
            if (x == 0) {
                positive = 0;
                negative = 0;
            }
            else if (x > 0) {
                positive++;
                negative = negative == 0 ? 0 : negative + 1;
            }
            else {
                int tmp  = positive;
                positive = negative == 0 ? 0 : negative + 1;
                negative = tmp + 1;
            }
            ans = max(ans, positive);
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube bFer5PdsgpY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

