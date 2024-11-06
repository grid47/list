
+++
authors = ["Crafted by Me"]
title = "Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
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


---
{{< youtube FJVQfaZo4oA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2456: Most Popular Video Creator](https://grid47.xyz/posts/leetcode_2456) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
