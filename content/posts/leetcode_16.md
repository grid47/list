
+++
authors = ["Crafted by Me"]
title = "Leetcode 16: 3Sum Closest"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 16: 3Sum Closest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube PXWT4wzkA6M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #17: Letter Combinations of a Phone Number](https://grid47.xyz/posts/leetcode_17) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

