
+++
authors = ["Crafted by Me"]
title = "Leetcode 1696: Jump Game VI"
date = "2019-03-12"
description = "Solution to Leetcode 1696"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-vi/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> dq = {0};
        
        for(int i = 1; i < n; i++) {
            
            nums[i] = nums[dq.front()] + nums[i];
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if(i - dq.front() >= k) dq.pop_front();
            
        }
        
        return nums[n - 1];
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

