
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 962: Maximum Width Ramp"
date = "2022-03-13"
description = "Solution to Leetcode 962"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-ramp/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        for(int i = 0; i < nums.size(); i++)
            if(s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
            while(!s.empty() && nums[s.top()] <= nums[i])
                res = max(res, i - s.top()), s.pop();
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
