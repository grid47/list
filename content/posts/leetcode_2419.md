
+++
authors = ["Crafted by Me"]
title = "Leetcode 2419: Longest Subarray With Maximum Bitwise AND"
date = "2018-03-20"
description = "In-depth solution and explanation for Leetcode 2419: Longest Subarray With Maximum Bitwise AND in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        int len = 0, ans = 0;
        for(int ele: nums) {
            if(ele == x) {
                ans = max(ans, ++len);
            } else len = 0;
        }
        return ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2420: Find All Good Indices](https://grid47.xyz/posts/leetcode_2420) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

