
+++
authors = ["Yasir"]
title = "Leetcode 1785: Minimum Elements to Add to Form a Given Sum"
date = "2019-12-09"
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

{{< highlight html >}}
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

