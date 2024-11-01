
+++
authors = ["Crafted by Me"]
title = "Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number"
date = "2018-11-17"
description = "Solution to Leetcode 2177"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num %3 != 0) return ans;
        return {num / 3 - 1, num/ 3, num/3 + 1};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

