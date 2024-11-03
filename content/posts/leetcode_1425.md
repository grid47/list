
+++
authors = ["Crafted by Me"]
title = "Leetcode 1425: Constrained Subsequence Sum"
date = "2020-12-08"
description = "In-depth solution and explanation for Leetcode 1425: Constrained Subsequence Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/constrained-subsequence-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        int res = nums[0];
        for(int i = 0; i < n; i++) {
            nums[i] += q.size() ? q.front() : 0;
            res = max(res, nums[i]);
            while(q.size() > 0 && nums[i] > q.back()) {
                q.pop_back();
            }
            if(nums[i] > 0) {
                q.push_back(nums[i]);
            }
            if(i >= k && q.size() && q.front() == nums[i - k]) {
                q.pop_front();
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1425.md" >}}
---
{{< youtube -IYZv-nOSys >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1426: Counting Elements](https://grid47.xyz/posts/leetcode_1426) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

