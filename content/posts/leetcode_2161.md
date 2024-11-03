
+++
authors = ["Crafted by Me"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2018-12-03"
description = "In-depth solution and explanation for Leetcode 2161: Partition Array According to Given Pivot in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for(auto num: nums) {
            if(num < pivot) low++;
            else if(num == pivot) same++;
        }
        high = low + same;
        same = low;
        low = 0;
        vector<int> res(nums.size(), 0);
        for(auto num: nums) {
            if(num < pivot) res[low++] = num;
            else if(num == pivot) res[same++] = num;
            else res[high++] = num;
        }
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2162: Minimum Cost to Set Cooking Time](https://grid47.xyz/posts/leetcode_2162) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

