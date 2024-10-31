
+++
authors = ["Crafted by Me"]
title = "Leetcode 2369: Check if There is a Valid Partition For The Array"
date = "2018-05-08"
description = "Solution to Leetcode 2369"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> nums, memo;
    
    bool dp(int idx) {
        if(idx == n) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
            if(dp(idx + 2)) return memo[idx] = true;
        }
        
        if(idx + 2 < n) {
            if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
                if(dp(idx + 3)) return memo[idx] = true;                
            }
            if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
                if(dp(idx + 3)) return memo[idx] =true;
            }
        }

        return memo[idx] = false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, -1);
        return dp(0);
    }
};
{{< /highlight >}}



---

{{< youtube HywUcx60BRo >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

