
+++
authors = ["Crafted by Me"]
title = "Leetcode 3162: Find the Number of Good Pairs I"
date = "2016-03-07"
description = "In-depth solution and explanation for Leetcode 3162: Find the Number of Good Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int res = 0, m = nums1.size(), n = nums2.size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(nums1[i] % (nums2[j] * k) == 0) res++;
        return res;
        
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3163: String Compression III](https://grid47.xyz/posts/leetcode_3163) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

