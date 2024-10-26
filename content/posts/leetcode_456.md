
+++
authors = ["Yasir"]
title = "Leetcode 456: 132 Pattern"
date = "2023-07-29"
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

**Code:**

{{< highlight html >}}
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

