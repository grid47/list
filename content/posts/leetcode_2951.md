
+++
authors = ["Crafted by Me"]
title = "Leetcode 2951: Find the Peaks"
date = "2016-10-04"
description = "In-depth solution and explanation for Leetcode 2951: Find the Peaks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-peaks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> res;
        for(int i = 1; i < nums.size() - 1; i++) {
            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                res.push_back(i);            
        }

        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2952: Minimum Number of Coins to be Added](https://grid47.xyz/posts/leetcode_2952) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

