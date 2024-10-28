
+++
authors = ["Yasir"]
title = "Leetcode 27: Remove Element"
date = "2024-10-02"
description = "Solution to Leetcode 27"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-element/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for(int node: nums)
            if(node != val)
            {
                nums[i] = node;
                i++;
            }
        
        return i;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

