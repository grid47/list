
+++
authors = ["Yasir"]
title = "Leetcode 1696: Jump Game VI"
date = "2020-03-08"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

