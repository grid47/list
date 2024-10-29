
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 16: 3Sum Closest"
date = "2024-10-14"
description = "Solution to Leetcode 16"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/3sum-closest/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int front;
        int sum = nums[0] + nums[1] + nums[2], sum1 = 0;

        for(int i = 0; i < nums.size(); i++) {

            front = i + 1;

            int back = nums.size() - 1;

            while( front < back ) {

                sum1 = nums[front] + nums[back] + nums[i];

                if (abs(sum1-target) <= abs(sum-target)) sum = sum1;

                     if(sum1 > target) back--;
                else if(sum1 < target) front++;
                else return sum1;

            }
        }

        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/16.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

