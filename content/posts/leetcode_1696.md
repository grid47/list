
+++
authors = ["Crafted by Me"]
title = "Leetcode 1696: Jump Game VI"
date = "2020-03-12"
description = "In-depth solution and explanation for Leetcode 1696: Jump Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1696.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1697: Checking Existence of Edge Length Limited Paths](https://grid47.xyz/posts/leetcode_1697) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

