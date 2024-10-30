
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 456: 132 Pattern"
date = "2023-08-02"
description = "Solution to Leetcode 456"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/132-pattern/description/)

---
{{< youtube TfgWauHLuRE >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        int prv = INT_MIN;
        stack<int> stk;
        
        for(int i = n - 1; i >= 0; i--) {

            if (nums[i] < prv) return true;

            while(!stk.empty() && nums[i] > stk.top()) {

                prv = stk.top();
                stk.pop();

            }

            stk.push(nums[i]);
        }

        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/456.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

