
+++
authors = ["Crafted by Me"]
title = "Leetcode 1837: Sum of Digits in Base K"
date = "2019-10-23"
description = "In-depth solution and explanation for Leetcode 1837: Sum of Digits in Base K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-digits-in-base-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumBase(int n, int k) {
        int res=0;
        while(n!=0)
        {
            res+=(n%k);
            n/=k;
        }
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1838: Frequency of the Most Frequent Element](https://grid47.xyz/posts/leetcode_1838) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

