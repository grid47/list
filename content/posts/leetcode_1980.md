
+++
authors = ["Crafted by Me"]
title = "Leetcode 1980: Find Unique Binary String"
date = "2019-06-02"
description = "In-depth solution and explanation for Leetcode 1980: Find Unique Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-unique-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; i++)
        ans += nums[i][i] == '0'? '1':'0';
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube aHqn4Dynd1k >}}

| Next : [LeetCode #1981: Minimize the Difference Between Target and Chosen Elements](grid47.xyz/leetcode_1981) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

