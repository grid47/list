
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3162: Find the Number of Good Pairs I"
date = "2016-03-05"
description = "Solution to Leetcode 3162"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

