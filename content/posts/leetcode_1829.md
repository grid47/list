
+++
authors = ["Crafted by Me"]
title = "Leetcode 1829: Maximum XOR for Each Query"
date = "2019-10-31"
description = "In-depth solution and explanation for Leetcode 1829: Maximum XOR for Each Query in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        int ui = 0;
        for(int x : nums)
            ui ^= x;
        int msk = (1 << bit) - 1;
        
        
        

        
        int res = ui ^ msk;
        vector<int> ans;
        ans.push_back(res);
        while(nums.size() > 1) {
            
            res ^= nums.back();
            nums.pop_back();
            ans.push_back(res);
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1829.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1830: Minimum Number of Operations to Make String Sorted](https://grid47.xyz/posts/leetcode_1830) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

