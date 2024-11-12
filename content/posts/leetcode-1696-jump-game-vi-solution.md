
+++
authors = ["grid47"]
title = "Leetcode 1696: Jump Game VI"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1696: Jump Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
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
{{< youtube dHAsYTvbbj4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1700: Number of Students Unable to Eat Lunch](https://grid47.xyz/posts/leetcode-1700-number-of-students-unable-to-eat-lunch-solution/) |
| --- |
