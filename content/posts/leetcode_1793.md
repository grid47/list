
+++
authors = ["Crafted by Me"]
title = "Leetcode 1793: Maximum Score of a Good Subarray"
date = "2018-12-05"
description = "Solution to Leetcode 1793"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k, mini = nums[k], res = nums[k];
        
        int n = nums.size();

        while(i > 0 || j < n - 1) {
            
                 if(i == 0)                    j++;
            else if(j == n - 1)                i--;
            else if(nums[i - 1] < nums[j + 1]) j++;
            else                               i--;
            
            mini = min(mini, min(nums[i], nums[j]));
            res  = max(res, mini * (j - i + 1));
   
        }

        return res;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

