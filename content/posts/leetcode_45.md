
+++
authors = ["Crafted by Me"]
title = "Leetcode 45: Jump Game II"
date = "2024-09-18"
description = "In-depth solution and explanation for Leetcode 45: Jump Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int far = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            far = max(far, i + nums[i]);
            if(i == cur) {
                cur = far;
                jumps++;
            }
        }
        return jumps;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/45.md" >}}
---
{{< youtube CsDI-yQuGeM >}}

"| 46: Permutations |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

