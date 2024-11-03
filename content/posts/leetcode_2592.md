
+++
authors = ["Crafted by Me"]
title = "Leetcode 2592: Maximize Greatness of an Array"
date = "2017-09-28"
description = "In-depth solution and explanation for Leetcode 2592: Maximize Greatness of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-greatness-of-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // 1 1 1 2 3 3 5
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> pos;
        pos[-1] = -1;
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
            if(it == nums.end()) break;
            int idx = it - nums.begin();
            pos[i] = idx;
            if(idx == n - 1) break;
        }
        return pos.size() - 1;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2593: Find Score of an Array After Marking All Elements](https://grid47.xyz/posts/leetcode_2593) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

