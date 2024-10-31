
+++
authors = ["Crafted by Me"]
title = "Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three"
date = "2018-02-11"
description = "Solution to Leetcode 2455"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
     int Total_Sum=0;
        int Total_Number=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 && nums[i]%3==0)
            {
                Total_Sum+=nums[i];
                Total_Number++;
            }
        }      
        if(Total_Sum==0) return 0;
        return Total_Sum/Total_Number;   
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

