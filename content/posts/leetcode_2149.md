
+++
authors = ["Crafted by Me"]
title = "Leetcode 2149: Rearrange Array Elements by Sign"
date = "2018-12-15"
description = "In-depth solution and explanation for Leetcode 2149: Rearrange Array Elements by Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int idxpos = 0, idxneg = 1;
        for(int num: nums) {
            if(num > 0) {
                ans[idxpos] = num;
                idxpos += 2;
            }
            if(num < 0) {
                ans[idxneg] = num;
                idxneg += 2;
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

