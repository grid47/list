
+++
authors = ["Crafted by Me"]
title = "Leetcode 1027: Longest Arithmetic Subsequence"
date = "2022-01-10"
description = "In-depth solution and explanation for Leetcode 1027: Longest Arithmetic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<unordered_map<int, int>> mp;
        mp.resize(n);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[j] - nums[i];
                if(mp[j].count(d)) mp[i][d] = max(mp[i][d], mp[j][d] + 1);
                else mp[i][d] = max(mp[i][d], 2);
                res = max(mp[i][d], res);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1027.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1028: Recover a Tree From Preorder Traversal](https://grid47.xyz/posts/leetcode_1028) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

