
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1748: Sum of Unique Elements"
date = "2020-01-16"
description = "Solution to Leetcode 1748"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-unique-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum= 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]] <= 1)
                sum+= nums[i];
        }
        return sum;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

