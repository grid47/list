
+++
authors = ["Crafted by Me"]
title = "Leetcode 2302: Count Subarrays With Score Less Than K"
date = "2017-07-14"
description = "Solution to Leetcode 2302"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, j = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while(sum * (i - j + 1) >= k) sum -= nums[j++];
            
            res += (i - j + 1);
        }
        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

