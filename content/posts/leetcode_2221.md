
+++
authors = ["Crafted by Me"]
title = "Leetcode 2221: Find Triangular Sum of an Array"
date = "2018-10-04"
description = "In-depth solution and explanation for Leetcode 2221: Find Triangular Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);        
        for(int i = n; i > 1; i--) {
            int k = i - 1;
            for(int j = k - 1; j >= 0; j--)
                arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
            
            nums = arr;
        }
        
        return nums[0];
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

