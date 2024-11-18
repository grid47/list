
+++
authors = ["grid47"]
title = "Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2455: Average Value of Even Numbers That Are Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "FJVQfaZo4oA"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2455.md" >}}
---
{{< youtube FJVQfaZo4oA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2456: Most Popular Video Creator](https://grid47.xyz/leetcode/solution-2456-most-popular-video-creator/) |
| --- |
