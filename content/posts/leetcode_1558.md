
+++
authors = ["Crafted by Me"]
title = "Leetcode 1558: Minimum Numbers of Function Calls to Make Target Array"
date = "2020-07-27"
description = "Solution to Leetcode 1558"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int cnt = 0;
        
        int n = nums.size();
        int zeros = 0;

        while(zeros != n) {
        
            for(int i = 0; i < n; i++) {

                if(nums[i] & 1) cnt++, nums[i]--;

            }
            
            zeros = 0;
            int ch = true;
            for(int i = 0; i < n; i++) {

                if(nums[i] > 0 && ch) cnt++, ch = false;
                
                nums[i] /= 2;

                if(nums[i] == 0) zeros++;
            }            
        }
        
        
        return cnt;
    }

};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

