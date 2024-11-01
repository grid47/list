
+++
authors = ["Crafted by Me"]
title = "Leetcode 1785: Minimum Elements to Add to Form a Given Sum"
date = "2019-12-14"
description = "Solution to Leetcode 1785"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for(int x: nums)
            sum += x;
        long diff = abs(goal - sum);
        if(diff % limit == 0) return diff/limit;
        else return diff/limit + 1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

