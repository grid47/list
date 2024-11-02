
+++
authors = ["Crafted by Me"]
title = "Leetcode 1630: Arithmetic Subarrays"
date = "2019-05-17"
description = "Solution to Leetcode 1630"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/arithmetic-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
            sort(begin(n), end(n));
            for (j = 2; j < n.size(); ++j)
                if (n[j] - n[j - 1] != n[1] - n[0])
                    break;
            res.push_back(j == n.size());
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

