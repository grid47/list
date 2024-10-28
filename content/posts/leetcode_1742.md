
+++
authors = ["Yasir"]
title = "Leetcode 1742: Maximum Number of Balls in a Box"
date = "2020-01-22"
description = "Solution to Leetcode 1742"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        vector<int> box (46,0);
        for(int i = lowLimit;i<=highLimit;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp)
            {
                sum = sum + temp%10;
                temp = temp/10;
            }
            box[sum]++;
        }
        
        return *max_element(box.begin(),box.end());
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

