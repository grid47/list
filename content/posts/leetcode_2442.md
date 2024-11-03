
+++
authors = ["Crafted by Me"]
title = "Leetcode 2442: Count Number of Distinct Integers After Reverse Operations"
date = "2018-02-25"
description = "In-depth solution and explanation for Leetcode 2442: Count Number of Distinct Integers After Reverse Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rev(int num) {
        int res = 0;
        while(num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        set<int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
            cnt.insert(rev(nums[i]));
        }
        
        return cnt.size();        
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2443: Sum of Number and Its Reverse](grid47.xyz/leetcode_2443) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

