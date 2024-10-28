
+++
authors = ["Yasir"]
title = "Leetcode 324: Wiggle Sort II"
date = "2023-12-10"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

