
+++
authors = ["Crafted by Me"]
title = "Leetcode 324: Wiggle Sort II"
date = "2022-12-13"
description = "Solution to Leetcode 324"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/wiggle-sort-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1 + 2 * i) % (n|1)]
        
        int i = 0, j = 0, k = n - 1;
        
        while(j <= k) {
            if(A(j) < mid)
                swap(A(j), A(k--));
            else if(A(j) > mid)
                swap(A(i++), A(j++));
            else j++;
        }
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/324.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

