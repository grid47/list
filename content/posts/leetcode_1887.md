
+++
authors = ["Crafted by Me"]
title = "Leetcode 1887: Reduction Operations to Make the Array Elements Equal"
date = "2019-09-02"
description = "Solution to Leetcode 1887"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        int ops = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; i--) {
            
            if(nums[i] == nums[i + 1]) continue;
            ops += (n - 1 - i);
            
        }
        
        return ops;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

