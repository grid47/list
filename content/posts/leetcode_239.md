
+++
authors = ["Crafted by Me"]
title = "Leetcode 239: Sliding Window Maximum"
date = "2024-03-08"
description = "Solution to Leetcode 239"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-window-maximum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ret;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            
            dq.push_back(i);
            if(i >= k - 1) ret.push_back(nums[dq.front()]);
            
        }
        return ret;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/239.md" >}}
- by gpt
        
---
{{< youtube DfljaUwZsOk >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

