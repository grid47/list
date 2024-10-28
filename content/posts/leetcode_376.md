
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 376: Wiggle Subsequence"
date = "2023-10-19"
description = "Solution to Leetcode 376"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/wiggle-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wiggleMaxLength(vector<int> nums) {
        if(nums.size() == 0) return 0;
        
        int n = nums.size();
        
        vector<int> up(n, 0);
        vector<int> down(n, 0);        
        
        up[0] = 1;
        down[0] = 1;
        
        for(int i = 1; i < n; i++) {
                 if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else if(nums[i] > nums[i - 1]) {            
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];                
            }
            else {
                down[i] = down[i - 1];
                up[i]   =   up[i - 1];                
            }
        }
        
        return max(down[n - 1], up[n - 1]);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

