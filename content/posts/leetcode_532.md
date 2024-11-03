
+++
authors = ["Crafted by Me"]
title = "Leetcode 532: K-diff Pairs in an Array"
date = "2023-05-20"
description = "In-depth solution and explanation for Leetcode 532: K-diff Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        int res = 0;
        for(auto const &[i, j] : mp)
            if((k > 0 && mp.count(i - k)) ||
              (k == 0 && (j > 1)) )
                res++;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/532.md" >}}
---


"| 533: Lonely Pixel II |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

