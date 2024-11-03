
+++
authors = ["Crafted by Me"]
title = "Leetcode 2958: Length of Longest Subarray With at Most K Frequency"
date = "2016-09-27"
description = "In-depth solution and explanation for Leetcode 2958: Length of Longest Subarray With at Most K Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        map<int, int> mp;
        int j = 0, res = 1, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            while(mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2959: Number of Possible Sets of Closing Branches](https://grid47.xyz/posts/leetcode_2959) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

