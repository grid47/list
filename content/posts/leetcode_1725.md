
+++
authors = ["Crafted by Me"]
title = "Leetcode 1725: Number Of Rectangles That Can Form The Largest Square"
date = "2020-02-12"
description = "In-depth solution and explanation for Leetcode 1725: Number Of Rectangles That Can Form The Largest Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:rectangles){
            int m=min(i[0],i[1]);
            ans=max(ans,m);
            mp[m]++;
        }
        
        return mp[ans];

    }
};
{{< /highlight >}}


---


| Next : [LeetCode #1726: Tuple with Same Product](grid47.xyz/leetcode_1726) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

