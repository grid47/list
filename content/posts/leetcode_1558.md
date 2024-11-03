
+++
authors = ["Crafted by Me"]
title = "Leetcode 1558: Minimum Numbers of Function Calls to Make Target Array"
date = "2020-07-28"
description = "In-depth solution and explanation for Leetcode 1558: Minimum Numbers of Function Calls to Make Target Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

