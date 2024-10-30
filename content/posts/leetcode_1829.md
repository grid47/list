
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1829: Maximum XOR for Each Query"
date = "2019-10-29"
description = "Solution to Leetcode 1829"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        int ui = 0;
        for(int x : nums)
            ui ^= x;
        int msk = (1 << bit) - 1;
        
        
        

        
        int res = ui ^ msk;
        vector<int> ans;
        ans.push_back(res);
        while(nums.size() > 1) {
            
            res ^= nums.back();
            nums.pop_back();
            ans.push_back(res);
            
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

